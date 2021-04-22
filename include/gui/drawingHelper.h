#pragma once
#include <3ds.h>

enum {
    VALIGN_TOP =        0 << 8,
    VALIGN_CENTER =     1 << 8,
    VALIGN_BOTTOM =     1 << 9
};

void drawBox(float x,float y,float z, float w,float h, float thickness, u32 color1, u32 color2);
void drawBoxSingleColor(float x,float y,float z, float w,float h, float thickness, u32 color);

void draw3dBox(float x,float y,float z, float w,float h, float thickness, u32 bg, u32 border1, u32 border2);
void drawText(float x, float y, float z, float w, float h, float scale, u32 flags, u32 bgColor, u32 color, const char *value);
