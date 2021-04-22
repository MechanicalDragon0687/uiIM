// #include "gui/Label.hpp"
// #include "gui/Element.hpp"
// #include "gui/Theme.hpp"
// #include "gui/font.hpp"
// #include "gui/DataTypes.hpp"
// #include "gui/drawingHelper.hpp"
// #include <string>

// Label::Label(Vector3f location, float scale, std::string label, uint32_t flags, std::string id) : ElementWithLabel(location,{0,0},label,id) {
//     this->flags=flags;
//     this->size = getTextDimensions(label,scale);
//     this->scale = scale;
//     this->clr = THEME_TEXT;
// }
// void Label::setColor(uint32_t color) {
//     this->clr = color;
// }
// void Label::draw(Vector3f at) {
//     Vector3f loc = at+this->getLocationAbsolute();
//     drawText(loc,{0,0},this->scale,this->flags,0,this->clr,this->label);
// }
// void Label::setLabel(std::string label) {
//     ElementWithLabel::setLabel(label);
//     this->size=getTextDimensions(label,this->scale);
// }
#include <3ds.h>
#include <citro2d.h>
#include "gui/drawingHelper.h"
void label(float x, float y, float z, float w, float h, u32 bg, u32 fontclr, float scale, const char* title, u32 flags) {
    drawText(x,y,z,w,h, scale, flags, bg, fontclr, title);
}