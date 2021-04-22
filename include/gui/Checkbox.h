#pragma once
#include <3ds.h>
#include "gui/Inputs.h"
void checkbox(inputData lastData, inputData data, float x, float y, float z, float w, float h, u32 clrborder, u32 clrFill, u32 clrFont, float scale, const char* value, bool* checked);