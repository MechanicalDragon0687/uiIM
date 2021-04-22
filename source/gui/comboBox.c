// #include <3ds.h>
// #include <citro2d.h>
// #include "gui/Theme.h"
// #include "gui/drawingHelper.h"
// #include "gui/Inputs.h"
// struct option { 
//     char* display;
//     char* value;
//     int type;
// };
// void comboBox(inputData lastData, inputData data, float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr1, u32 borderclr2, u32 fontclr, float scale, const char* title, struct option* entries, int optionCount, int selected) {
//         draw3dBox
//         panel(x,y,z,w,h,4,bg,THEME_PANEL_BORDER1,THEME_PANEL_BORDER2,THEME_TEXT,scale,title);

// 		// char count[500]={0};
// 		// sprintf(count,"%f",heldLen);
// 		// label(10,150,0,0,0,0,0,THEME_TEXT,0.67,(heldKey==KEY_DOWN)?"HELD":"NOT HELD",0);
// 		// label(10,170,0,0,0,0,0,THEME_TEXT,0.67,count,0);
// 		float wid = w-PANEL_MARGIN*2-PANEL_BORDER*2-PANEL_PADDING_LEFT-PANEL_PADDING_RIGHT;
// 		float lx = PANEL_BORDER+PANEL_MARGIN+PANEL_PADDING_LEFT;
//             if (fileCount > 0) {
// 			//void listEntry(float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr, u32 fontclr, float scale, const char* title, u32 flags) {
// 			for (int i=selected-1;i>=0 && i>selected-4;i--)
// 				listEntry(lx,y+h/2+(28*(i-selected)),0,wid,26,2,bg,borderclr,fontclr,scale,dirEntries[i].d_name,C2D_AlignCenter);
// 			// char selFN[300];
// 			// sprintf(selFN,"> %s",dirEntries[selected].d_name);
// 			listEntry(lx,y+h/2,0,wid,26,2,fontclr,borderclr,bg,scale,dirEntries[selected].d_name,C2D_AlignCenter);
// 			// label(10,55,0,0,0,0,0,THEME_TEXT,0.50,selFN,0);
// 			for (int i=selected+1;i<fileCount && i<selected+4;i++)
// 				listEntry(lx,y+h/2+(26*(i-selected)),0,wid,26,2,bg,borderclr,fontclr,scale,dirEntries[i].d_name,C2D_AlignCenter);
// 		}
//     if(((data.kUp & KEY_TOUCH) > 0) && isIn(x,y,w,h,lastData.touch) && isIn(x,y,w,h,data.touch))
//         *checked=!*checked;
//     drawBoxSingleColor(x,y,z,w,h,CHECKBOX_BORDER,clrborder);
//     if (*checked==true) {
//         C2D_DrawRectSolid(CHECKBOX_PADDING+x+CHECKBOX_BORDER/2,CHECKBOX_PADDING+y+CHECKBOX_BORDER/2,z,w-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),h-(CHECKBOX_PADDING*2+(CHECKBOX_BORDER)),clrFill);
//     }
//     drawText(x+w*1.5,y,z,w,h,scale,0,0,clrFont,value);
// }