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


static void *createFileItemFunc2(){
	std::cout<<"this is createFileItemFunc2\n";
	return new FileItem;
}


int main() {

	FileItem* fileItemPtr= static_cast<FileItem*>(ClassFactory::getInstance().getItemObject("FileItem"));
	fileItemPtr->Print();

	std::cout<<"change createObjFunc\n";
	ClassFactory::getInstance().registItemObject("FileItem",createFileItemFunc2);
	fileItemPtr=static_cast<FileItem*>(ClassFactory::getInstance().getItemObject("FileItem"));
	fileItemPtr->Print();
	//do not need to delete fileItemPtr; ~ClassFactory() will do it;

	ConsoleItem* consoleItemPtr= static_cast<ConsoleItem*>(ClassFactory::getInstance().getItemObject("ConsoleItem"));
	consoleItemPtr->Print();

	return 0;
}