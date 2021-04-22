#include <3ds.h>
#include <citro2d.h>
#include "gui/Checkbox.h"
#include "gui/drawingHelper.h"
#include "gui/Theme.h"
#include "gui/Inputs.h"


// Checkbox::Checkbox(Vector3f location, Vector2f size, float scale, std::string label, bool checked, std::string id) : ElementWithLabel(location,size,label,id) {
//     this->scale=scale;
//     this->checked=checked;
//     this->registerListener({Click,[this](eventData d){this->checked=!this->checked; return true;}});
// }
// void Checkbox::draw(Vector3f at) {
//     Vector3f loc = this->getLocationAbsolute();
//     float z=at.z+loc.z;
//     Vector2f minLoc = _asV2F((loc+at));
//     Vector2f maxLoc = minLoc+this->size;
//     drawBox(minLoc,maxLoc,z,CHECKBOX_BORDER,THEME_CHECKBOX_BORDER);
//     if (this->checked) {
//         C2D_DrawRectSolid(CHECKBOX_PADDING+minLoc.x+CHECKBOX_BORDER/2,CHECKBOX_PADDING+minLoc.y+CHECKBOX_BORDER/2,z,this->size.x-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),this->size.y-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),THEME_CHECKBOX_FILL);
//     }
//     drawText(_asV3F(minLoc,z)+Vector3f{this->size.x,0,0},{0,0},this->scale,0,0,CHECKBOX_TEXT," "+this->label);
// }
#define isIn(x,y,w,h,touch) (touch.px >= x && touch.px <= x+w && touch.py >= y && touch.py <=y+h)

void checkbox(inputData lastData, inputData data, float x, float y, float z, float w, float h, u32 clrborder, u32 clrFill, u32 clrFont, float scale, const char* value, bool *checked) {
    if(((data.kUp & KEY_TOUCH) > 0) && isIn(x,y,w,h,lastData.touch) && isIn(x,y,w,h,data.touch))
        *checked=!*checked;
    drawBoxSingleColor(x,y,z,w,h,CHECKBOX_BORDER,clrborder);
    if (*checked==true) {
        C2D_DrawRectSolid(CHECKBOX_PADDING+x+CHECKBOX_BORDER/2,CHECKBOX_PADDING+y+CHECKBOX_BORDER/2,z,w-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),h-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),clrFill);
    }
    drawText(x+w*1.5,y,z,w,h,scale,0,0,clrFont,value);
}