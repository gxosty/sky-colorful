//
// Created by gxost on 22/01/2025
//

#include "main.h"
#include "include/Cipher/Cipher.h"
#include "include/imgui/imgui.h"
#include "include/misc/Logger.h"

#include <colorful/colorful.hpp>

static bool g_initialized = false;


void Menu(bool* menu_open) {
    if (*menu_open)
    {
        clr::draw(menu_open);
    }
}

void InitLate() {

}

void Init() {
    g_initialized = clr::initialize();

    if (!g_initialized)
    {
        LOGE("Failed initializing 'colorful'");
    }
}