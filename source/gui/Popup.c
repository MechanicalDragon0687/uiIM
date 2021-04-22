// #include "gui/DataTypes.hpp"
// #include "gui/Panel.hpp"
// #include "gui/Dialog.hpp"
// #include "gui/DialogButton.hpp"
// #include "gui/font.hpp"
// #include "gui/Label.hpp"
// #include "gui/Theme.hpp"
// #include <vector>
// #include <string>
// #include <functional>
// Dialog::Dialog(Vector3f location, Vector2f size, std::string id, std::string label, std::string message, std::vector<std::string> buttons, std::function<void(int)> onComplete) : Panel(location,size,id,label,0) {
//     this->addChild(new Label({this->size.x*2/12,0,0},TEXT_SCALE,message,0,id+".message"));
//     for (size_t i=0;i<buttons.size();i++) {
//         //float szy = std::max(size.y/12,20.0f);
//         //float szx = std::max(20.0f,size.x/(buttons.size()+1)-BUTTON_MARGIN);
//         Vector2f sz = getTextDimensions(buttons[i],TEXT_SCALE);
//         float bx = (i+1)*((size.x/(buttons.size()+2))+((i>0)?BUTTON_MARGIN:0));
//         float by = size.y-
//                 (PANEL_MARGIN*2) - 
//                 (PANEL_BORDER*2) - 
//                 (PANEL_PADDING_TOP+PANEL_PADDING_BOTTOM)-(sz.y+BUTTON_PADDING_TOP+BUTTON_PADDING_BOTTOM);

//         std::string bid = id+".button"+std::to_string(i);
//         this->addChild(
//             new DialogButton(this,i,{bx,by,0}, bid,buttons[i])
//         );
//     }
//     this->registerListener({Close,[onComplete,this](eventData data){
//         onComplete(this->getResult());
//         return true;
//     }});
//         this->registerListener({KeyDown,
//             [this](eventData data){ 
//                 if (data.key & KEY_A){ 
//                     this->setResult(0); return true; 
//                 }else if(data.key & KEY_B) {
//                     this->setResult(-1); return true;
//                 }
//                 return false;
//             }
//         });
//     this->hide();
// }
// void Dialog::setResult(int i) {
//     this->result=i;
//     this->complete();
//     this->event({Close,0});
// }

#include <3ds.h>
#include <citro2d.h>
#include "gui/Panel.h"
#include "gui/Popup.h"
void popup(float x, float y, float z, float w, float h, u32 bg, u32 borderclr1, u32 fontclr, float scale, const char* title, const char* message) {
    panel(x,y,z,w,h,3,bg,borderclr1,borderclr1,fontclr,scale,title);
    
    float tw,th;
    C2D_TextBuf buf = C2D_TextBufNew(4096);
    C2D_Text t;
    C2D_TextParse(&t,buf,message);
    C2D_TextGetDimensions(&t,scale,scale,&tw,&th);
    C2D_TextOptimize(&t);
    C2D_DrawText(&t,C2D_WithColor,x+(w/2)-(tw/2),y+(h/3),z,scale,scale,fontclr);
    C2D_TextBufDelete(buf);
}