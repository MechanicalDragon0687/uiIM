#pragma once

#include <3ds.h>
#include "gui/Inputs.h"
int dialog(inputData oldData, inputData data, float x, float y, float z, float w, float h, u32 bg, u32 borderclr1, u32 fontclr, float scale, const char* title, const char* message, u32 buttonborder1, u32 buttonborder2, u32 buttonbg, u32 buttontext, const char* options[], u8 optionCount);