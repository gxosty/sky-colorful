#include <Cipher/Cipher.h>
#include <Cipher/CipherUtils.h>
#include <misc/Logger.h>

#include "sky/outfit.hpp"

#include <cstdint>
#include <vector>

#define SETUP_HOOK(_func, func_addr) \
    (new CipherHook()) \
    ->set_Hook((uintptr_t)my##_func) \
    ->set_Callback((uintptr_t)&orig##_func) \
    ->set_Address(func_addr, false)->Fire();

#define HOOK_DEF(ret, func, ...) unsigned long addr##func; ret (*orig##func)(__VA_ARGS__); ret my##func(__VA_ARGS__)

namespace clr
{
    extern std::vector<Outfit> _outfits;
}

namespace clr::hooks
{

    HOOK_DEF(bool, _outfit_option__serialize, uintptr_t outfit_option_ptr, uintptr_t json_object)
    {
        bool res = orig_outfit_option__serialize(outfit_option_ptr, json_object);
        clr::_outfits.emplace_back(outfit_option_ptr);
        return res;
    }

    bool initialize()
    {
        const char* outfit_option__serialize__pattern = "F4 4F 0F A9 FD 83 02 91 28 00 40 B9 68 00 00 34 F4 03 1F 2A 26 07 00 14";
        uintptr_t outfit_option__serialize__address = CipherUtils::CipherScanPattern(
            outfit_option__serialize__pattern,
            Flags::ReadAndExecute
        );

        if (!outfit_option__serialize__address)
        {
            LOGE("OutfitOption::Serialize scan failed");
            return false;
        }

        LOGI("OutfitOption::Serialize address found, hooking...");
        SETUP_HOOK(_outfit_option__serialize, outfit_option__serialize__address - 0x18);
        LOGI("Done");

        return true;
    }
}