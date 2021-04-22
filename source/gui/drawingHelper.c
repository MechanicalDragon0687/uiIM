#include <3ds.h>
#include <citro2d.h>
#include "gui/drawingHelper.h"

void drawBox(float x,float y,float z, float w,float h, float thickness, u32 color1, u32 color2) {
    //top
    C2D_DrawLine(x-thickness/2,y,color1,(x+w)+thickness/2,y,color1,thickness,z);
    //left
    C2D_DrawLine(x,y,color1,x,(y+h)+thickness/2,color1,thickness,z);
    //bottom
    C2D_DrawLine((x+w)+thickness/2,(y+h),color2,x+thickness/2,(y+h),color2,thickness,z);
    //right
    C2D_DrawLine((x+w),(y+h),color2,(x+w),y+thickness/2,color2,thickness,z);
}
void drawBoxSingleColor(float x,float y,float z, float w,float h, float thickness, u32 color) {
    drawBox(x,y,z,w,h,thickness,color,color);
}

void draw3dBox(float x,float y,float z, float w,float h, float thickness, u32 bg, u32 border1, u32 border2) {
            //bg
            C2D_DrawRectSolid(x,y,z,w,h,bg);
            //borders
            drawBox(x,y,z,w,h,thickness,border1,border2);
            //bottom-left-corner
            C2D_DrawTriangle(x+thickness/2,(y+h)-thickness/2,border2,x-thickness/2,(y+h)+thickness/2,border2,x+thickness/2,(y+h)+thickness/2,border2,z);
            //top-right-corner
            C2D_DrawTriangle((x+w)+thickness/2,y-thickness/2,border2,(x+w)-thickness/2,y+thickness/2,border2,(x+w)+thickness/2,y+thickness/2,border2,z);
}
void drawText(float x, float y, float z, float w, float h, float scale, u32 flags, u32 bgColor, u32 color, const char *value) {
            C2D_TextBuf buf=C2D_TextBufNew(4096);
            C2D_Text text;
            float tw,th;
            C2D_TextParse(&text,buf,value);
            C2D_TextGetDimensions(&text,scale,scale,&tw,&th);
            if (flags & VALIGN_CENTER) {
                y+=h/2;
                y-=th/2;
            }else if(flags & VALIGN_BOTTOM){
                flags|= C2D_AtBaseline;
            }
            C2D_TextOptimize(&text);
            if ((bgColor & 0xFF000000) > 0) {
                C2D_DrawRectSolid(x-tw/2-3*scale,y-3*scale,z,tw+6*scale,th+6*scale,bgColor);
            }
            C2D_DrawText(&text,(flags&0xFF) | C2D_WithColor,x,y,z,scale,scale,color);
            C2D_TextBufDelete(buf);
}