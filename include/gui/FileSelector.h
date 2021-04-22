#pragma once

#include <3ds.h>
#include <dirent.h>
#include "gui/Inputs.h"
struct directory_entry {
    unsigned char   d_type;
    char            d_name[256];
    char            path[256];
};
struct heldKeyTracker { 
    u32 key;
    double time;
    TickCounter heldTickCounter;
};
struct fileListData {
    int selected;
    struct directory_entry* dirEntries;
    int fileCount;
    char path[1024];
};
int fileList(inputData oldData, inputData inputs, struct heldKeyTracker* heldKey, float x, float y, float z, float w, float h, float thickness, u32 bg, u32 borderclr, u32 fontclr, float scale, const char* title, struct fileListData* listData);
int generateDirList(struct directory_entry** entries, const char* path, const char* filter, bool showHidden);