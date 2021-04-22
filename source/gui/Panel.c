#include <3ds.h>
#include <citro2d.h>
#include "gui/Panel.h"
#include "gui/Theme.h"
#include "gui/drawingHelper.h"

void panel(float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr1, u32 borderclr2, u32 fontclr, float scale, const char* title) {
    draw3dBox(x+PANEL_MARGIN,y+PANEL_MARGIN,z,w-PANEL_MARGIN*2,h-PANEL_MARGIN*2,thickness, bg,borderclr1,borderclr2);
    size_t titleLen = strlen(title);
    if (titleLen>0)
        drawText(x+w/2,y,z,w,thickness+PANEL_MARGIN*2, scale, C2D_AlignCenter | VALIGN_CENTER, bg, fontclr, title);

}