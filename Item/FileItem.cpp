//
// Created by root on 18-11-23.
//

#include "FileItem.h"


FileItem::FileItem(): Item("FileItem"){}

void FileItem::Print() {
	LOG(INFO)<<className;
}
