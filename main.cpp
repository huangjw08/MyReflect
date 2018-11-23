#include "ClassFactory.h"
#include "FileItem.h"
#include "ConsoleItem.h"
#include <iostream>

#define REGISTRY(className) \
class className##Helper{\
public:\
	className##Helper(){ClassFactory::getInstance().registItemObject(#className,createClassNameFunc);}\
	static void *createClassNameFunc(){\
		return new className;\
	}\
};\
className##Helper className##helper;

REGISTRY(FileItem)
REGISTRY(ConsoleItem)


int main() {

	FileItem* fileItemPtr= static_cast<FileItem*>(ClassFactory::getInstance().getItemObject("FileItem"));
	fileItemPtr->Print();

	return 0;
}