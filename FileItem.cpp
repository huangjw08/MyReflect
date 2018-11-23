//
// Created by root on 18-11-23.
//

#include "FileItem.h"

FileItem::FileItem(): Item("FileItem"){}

void FileItem::Print() {
	std::cout<<className<<std::endl;
}
