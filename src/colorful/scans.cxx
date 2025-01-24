#include <Cipher/CipherUtils.h>
#include <misc/Logger.h>

#include <cstdint>

namespace clr
{
    extern uintptr_t _avatar_outfit_get_option;
}

namespace clr::scans
{
    bool initialize()
    {
        const char* avatar_outfit__get_option__pattern = "FD 7B BE A9 F4 4F 01 A9 FD 03 00 91 E9 83 01 D1 3F E9 7B 92 3F 28 00 71 A2 01 00 54";
        uintptr_t avatar_outfit__get_option__address = CipherUtils::CipherScanPattern(
            avatar_outfit__get_option__pattern,
            Flags::ReadAndExecute
        );

        if (!avatar_outfit__get_option__address)
        {
            LOGE("AvatarOutfit::GetOption scan failed");
            return false;
        }

        LOGI("AvatarOutfit::GetOption address found");
        _avatar_outfit_get_option = avatar_outfit__get_option__address;

        return true;
    }
}