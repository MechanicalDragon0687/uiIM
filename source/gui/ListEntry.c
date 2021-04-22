#include <3ds.h>
#include <citro2d.h>
#include "gui/drawingHelper.h"
//         C2D_DrawLine(topLeft.x,topLeft.y,THEME_LIST_ENTRY_BORDER,bottomRight.x,topLeft.y,THEME_LIST_ENTRY_BORDER,1,at.z);
//         Vector3f textLoc = {topLeft.x + LIST_ENTRY_PADDING_LEFT, topLeft.y , at.z};
        
//         drawText(textLoc,{0,this->size.y},this->scale,VALIGN_CENTER,0,(selected)?THEME_LIST_ENTRY_HIGHLIGHT_TEXT:THEME_LIST_ENTRY_TEXT,this->label);

void listEntry(float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr, u32 fontclr, float scale, const char* title, u32 flags) {
         C2D_DrawRectSolid(x,y,z,w,h,bg);
         C2D_DrawLine(x,y,borderclr,x+w,y,borderclr,thickness,z);
         drawText(x+w/2,y,z,w,h,scale,flags | VALIGN_CENTER,0,fontclr,title);

}