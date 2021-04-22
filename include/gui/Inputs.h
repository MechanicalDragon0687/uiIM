#pragma once
#include <3ds.h>
typedef struct s_inputData {
    touchPosition touch;
    u32 kDown;
    u32 kUp;
    u32 kHeld;
    u32 kRepeat;
} inputData;

