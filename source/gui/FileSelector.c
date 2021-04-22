#include <3ds.h>
#include <citro2d.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "gui/drawingHelper.h"
#include "gui/Theme.h"
#include "gui/FileSelector.h"
#include "gui/ListEntry.h"
#include "gui/Panel.h"
#include "gui/Inputs.h"
int cmpfunc (const void * a, const void * b) {
	if ((*(struct directory_entry*)a).d_type==(*(struct directory_entry*)b).d_type) {
   		return strcasecmp((*(struct directory_entry*)a).d_name, (*(struct directory_entry*)b).d_name);
	}else{
		int i = (((*(struct directory_entry*)a).d_type - (*(struct directory_entry*)b).d_type));
		return (i>0)?1:(i<0)?-1:0;
	}
	return 0;
}

double max(double a, double b) {
	return (a>b)?a:b;
}
double min(double a, double b) {
	return (a>b)?b:a;
}
double updateTick(double current, TickCounter* ticker, double maxValue) {
	osTickCounterUpdate(ticker);
	return min(current+osTickCounterRead(ticker),maxValue);
}


int fileList(inputData oldData, inputData inputs, struct heldKeyTracker* heldKey, float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr, u32 fontclr, float scale, const char* title, struct fileListData* listData) {

		panel(x,y,z,w,h,4,bg,THEME_PANEL_BORDER1,THEME_PANEL_BORDER2,THEME_TEXT,scale,title);
		// char count[500]={0};
		// sprintf(count,"%f",heldLen);
		// label(10,150,0,0,0,0,0,THEME_TEXT,0.67,(heldKey==KEY_DOWN)?"HELD":"NOT HELD",0);
		// label(10,170,0,0,0,0,0,THEME_TEXT,0.67,count,0);
		float wid = w-PANEL_MARGIN*2-PANEL_BORDER*2-PANEL_PADDING_LEFT-PANEL_PADDING_RIGHT;
		float lx = PANEL_BORDER+PANEL_MARGIN+PANEL_PADDING_LEFT;
		if (listData->fileCount > 0) {
			//void listEntry(float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr, u32 fontclr, float scale, const char* title, u32 flags) {
			for (int i=listData->selected-1;i>=0 && i>listData->selected-4;i--)
				listEntry(lx,y+h/2+(28*(i-listData->selected)),0,wid,26,2,bg,borderclr,fontclr,scale,listData->dirEntries[i].d_name,C2D_AlignCenter);
			// char selFN[300];
			// sprintf(selFN,"> %s",dirEntries[selected].d_name);
			listEntry(lx,y+h/2,0,wid,26,2,fontclr,borderclr,bg,scale,listData->dirEntries[listData->selected].d_name,C2D_AlignCenter);
			// label(10,55,0,0,0,0,0,THEME_TEXT,0.50,selFN,0);
			for (int i=listData->selected+1;i<listData->fileCount && i<listData->selected+4;i++)
				listEntry(lx,y+h/2+(26*(i-listData->selected)),0,wid,26,2,bg,borderclr,fontclr,scale,listData->dirEntries[i].d_name,C2D_AlignCenter);
		}

		if (heldKey->key!=0 && (inputs.kUp & heldKey->key)>0) {
			heldKey->key=0;
			heldKey->time=0;
		}
		if ((inputs.kDown & KEY_A)>0) {
			if (listData->dirEntries[listData->selected].d_type==DT_DIR) {
				// size_t l = strlen(curPath);
				// if (curPath[l-1]!='/') {
				// 	curPath[l]='/';
				// 	curPath[l+1]='\0';
				// }
				if (strcmp(listData->dirEntries[listData->selected].d_name,"..")==0) {
					return 2;//setParent(curPath);
				}else{
					return 1;strcat(listData->path,listData->dirEntries[listData->selected].path);
				}
				//fileCount = generateDirList(&dirEntries,curPath,".nds",false);
				//selected=0;
			}else if(listData->dirEntries[listData->selected].d_type==DT_REG) {
				return 1;
			}else if(listData->dirEntries[listData->selected].d_type==DT_LNK) {
				return 3;
				//install all
			}
		}
		else if ((inputs.kDown & KEY_B)>0) {
			// setParent(curPath);
			// fileCount = generateDirList(&dirEntries,curPath,".nds",false);
			// selected=0;
			return 2;
		}
					// osTickCounterUpdate(&TickKeyHeld);
		else if ((inputs.kHeld & KEY_DOWN) > 0 && heldKey->key == KEY_DOWN) {
			heldKey->time = updateTick(heldKey->time,&heldKey->heldTickCounter,1000);
			if (heldKey->time > 300) {
				listData->selected = (listData->selected+1>=listData->fileCount)?listData->fileCount-1:listData->selected+1;
				heldKey->time=250;
			}
		}else if ((inputs.kHeld & KEY_UP) > 0 && heldKey->key == KEY_UP) {
			heldKey->time = updateTick(heldKey->time,&heldKey->heldTickCounter,1000);
			if (heldKey->time > 300) {
				listData->selected = (listData->selected-1>=0)?listData->selected-1:0;
				heldKey->time=250;
			}
		}else if ((inputs.kHeld & KEY_RIGHT) > 0 && heldKey->key == KEY_RIGHT) {
			heldKey->time = updateTick(heldKey->time,&heldKey->heldTickCounter,1000);
			if (heldKey->time > 300) {
				listData->selected = (listData->selected+4>=listData->fileCount)?listData->fileCount-1:listData->selected+4;
				heldKey->time=200;
			}
		}else if ((inputs.kHeld & KEY_LEFT) > 0 && heldKey->key == KEY_LEFT) {
			heldKey->time = updateTick(heldKey->time,&heldKey->heldTickCounter,1000);
			if (heldKey->time > 300) {
				listData->selected = (listData->selected-4>=0)?listData->selected-4:0;
				heldKey->time=200;
			}
		}
			else if ((inputs.kDown & KEY_DOWN)>0) {
			listData->selected = (listData->selected+1>=listData->fileCount)?listData->fileCount-1:listData->selected+1;
			if (heldKey->key == 0) {
				osTickCounterStart(&heldKey->heldTickCounter);
				heldKey->key=KEY_DOWN;
			}
		}
		else if ((inputs.kDown & KEY_RIGHT)>0) {
			listData->selected = (listData->selected+4>=listData->fileCount)?listData->fileCount-1:listData->selected+4;
			if (heldKey->key == 0) {
				osTickCounterStart(&heldKey->heldTickCounter);
				heldKey->key=KEY_RIGHT;
			}
		}
		else if ((inputs.kDown & KEY_UP)>0) {
			listData->selected = (listData->selected-1>=0)?listData->selected-1:0;
			if (heldKey->key == 0) {
				osTickCounterStart(&heldKey->heldTickCounter);
				heldKey->key=KEY_UP;
			}
		}
		else if ((inputs.kDown & KEY_LEFT)>0) {
			listData->selected = (listData->selected-4>=0)?listData->selected-4:0;
			if (heldKey->key == 0) {
				osTickCounterStart(&heldKey->heldTickCounter);
				heldKey->key=KEY_LEFT;
			}
		}
		return 0;

}
bool isDir(struct dirent* ent) {
	return ent->d_type==DT_DIR;
}
bool isFile(struct dirent* ent) {
	return ent->d_type==DT_REG;
}
bool isHidden(struct dirent* ent) {
	return ent->d_name[0]=='.';
}
bool endsWith(const char* filter, const char* target) {
	size_t flen = strlen(filter); // 4
	size_t tlen = strlen(target); // 8
	if (tlen >= flen) // 8 >= 4
		return (strncasecmp(filter, target+(tlen-flen),flen)==0); // ".nds"
	return false;
}
int generateDirList(struct directory_entry** dirEntries, const char* path, const char* filter, bool showHidden) {
   	int entryCount=0;
   	free(*dirEntries);
  	struct directory_entry *entries=NULL;
  	DIR *d;
  	struct dirent *dir;
	bool isRoot = (strcmp(path,"/")==0);
	int extraEntries = 0;
  	d = opendir(path);
  	if (d) {
		extraEntries = ((isRoot)?0:1);
	  	bool hasNDS = false;
		while ((dir = readdir(d)) != NULL) {
			if (isHidden(dir) && !showHidden)
				continue;
			if (isFile(dir) && endsWith(filter,dir->d_name)) {
				hasNDS=true;
				entryCount += 1;
			}else if (isDir(dir)) {
				entryCount += 1;
			}
		}
		closedir(d);
		if (hasNDS)
			extraEntries++;
		entries = calloc(entryCount+extraEntries, sizeof(struct directory_entry));
		int i=extraEntries;
		d = opendir(path);
		while ((dir = readdir(d))!=NULL) {
			if (((isFile(dir) && endsWith(filter,dir->d_name)) || isDir(dir)) && (showHidden || !isHidden(dir)))  {
				strcpy(entries[i].path,dir->d_name);
				if (strlen(dir->d_name)>32) {
					strncpy(entries[i].d_name,dir->d_name,29);
					strcat(entries[i].d_name,"...");
				}else{
					strcpy(entries[i].d_name,dir->d_name);
				}
				entries[i].d_type=dir->d_type;
				i++;
			}
		}

		closedir(d);
		qsort(entries+extraEntries,entryCount,sizeof(struct directory_entry),cmpfunc);
		i=0;
		if (hasNDS) {
			strcpy(entries[i].d_name,"[Install All]");
			entries[i].d_type=DT_LNK;
			i++;
		}
		if (!isRoot) {
			strcpy(entries[i].d_name,"..");
			entries[i].d_type=DT_DIR;
			i++;
		}
  	}
	*dirEntries=entries;
	return entryCount+extraEntries;
}