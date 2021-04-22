#pragma once
#include <3ds.h>
#define PANEL_FLAG_ALIGN_CENTER     0
#define PANEL_FLAG_ALIGN_LEFT       1
#define PANEL_FLAG_ALIGN_RIGHT      1<<1

void panel(float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr1, u32 borderclr2, u32 fontclr, float scale, const char* title);
