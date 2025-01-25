//
// Created by gxost on 22/01/2025
//

#include "main.h"
#include "include/Cipher/Cipher.h"
#include "include/imgui/imgui.h"
#include "include/misc/Logger.h"

#include <colorful/colorful.hpp>

static bool g_initialized = false;
static bool g_initialized_late = false;


void Menu(bool* menu_open) {
    if (*menu_open && g_initialized && g_initialized_late)
    {
        clr::draw(menu_open);
    }
}

void InitLate() {
    g_initialized_late = true;
}

void Init() {
    g_initialized = clr::initialize();

    if (!g_initialized)
    {
        LOGE("Failed initializing 'colorful'");
    }
}