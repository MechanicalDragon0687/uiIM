
#include <3ds.h>
#include <citro2d.h>
#include "gui/drawingHelper.h"
#include "gui/Inputs.h"
#include "gui/Button.h"
#include "gui/Panel.h"
#include "gui/Theme.h"
int dialog(inputData oldData, inputData data, float x, float y, float z, float w, float h, u32 bg, u32 borderclr1, u32 fontclr, float scale, const char* title, const char* message, u32 buttonborder1, u32 buttonborder2, u32 buttonbg, u32 buttontext, const char* options[], u8 optionCount) {
    int ret = -1;
    panel(x,y,z,w,h,3,bg,borderclr1,borderclr1,fontclr,scale,title);
    
    float tw,th;
    C2D_TextBuf buf = C2D_TextBufNew(4096);
    C2D_Text t;
    C2D_TextParse(&t,buf,message);
    C2D_TextGetDimensions(&t,scale,scale,&tw,&th);
    C2D_TextOptimize(&t);
    C2D_DrawText(&t,C2D_WithColor,x+(w/2)-(tw/2),y+(h/3),z,scale,scale,fontclr);
    C2D_TextBufDelete(buf);

    // drawText(x+(w*2/5),y+(h*2/5),z,0,0,scale,0,bg,fontclr,message);
    for (int i=0;i<optionCount;i++) {
        float bx = (i+1)*((w/(optionCount+2))+((i>0)?BUTTON_MARGIN:0));
        float by = h-
                (PANEL_MARGIN*2) - 
                (PANEL_BORDER*2) - 
                (PANEL_PADDING_TOP+PANEL_PADDING_BOTTOM)-(15+BUTTON_PADDING_TOP+BUTTON_PADDING_BOTTOM);
        if (button(oldData,data,bx,by,z,w/(optionCount+2),(15+BUTTON_PADDING_TOP+BUTTON_PADDING_BOTTOM),buttonbg,buttonborder1,buttonborder2,buttontext,options[i]))
            ret = i;
    }
    return ret;

}