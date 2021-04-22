#include <3ds.h>
#include <citro2d.h>
#include "gui/Inputs.h"
#include "gui/drawingHelper.h"
#include "gui/Theme.h"

#define isIn(x,y,w,h,touch) (touch.px >= x && touch.px <= x+w && touch.py >= y && touch.py <=y+h)
bool button(inputData lastData, inputData data, float x, float y, float z, float w, float h, u32 bg, u32 clr1, u32 clr2, u32 fontclr, const char* value) {
    bool isDown = false;
    bool clicked=false;
    if ((((data.kDown|data.kHeld) & KEY_TOUCH)>0) && isIn(x,y,w,h,data.touch)) {
        isDown=true;
    }else if(((data.kUp & KEY_TOUCH) > 0) && isIn(x,y,w,h,lastData.touch) && isIn(x,y,w,h,data.touch)) {
        clicked=true;
    }
    // button
    draw3dBox(x,y,z,w,h,BUTTON_BORDER,bg,(isDown)?clr2:clr1,(isDown)?clr1:clr2);
    // label
    drawText(x+(w/2),y,z,w,h,TEXT_SCALE,C2D_AlignCenter | VALIGN_CENTER,0,fontclr,value);
    return clicked;
}