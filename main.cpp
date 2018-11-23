
#include "ClassFactory.h"
#include "FileItem.h"
#include "ConsoleItem.h"
#include <iostream>
#include <glog/logging.h>



#define REGISTRY(className) \
class className##Helper{\
public:\
	className##Helper(){ClassFactory::getInstance().registItemObject(#className,createClassNameFunc);}\
	static void *createClassNameFunc(){\
		LOG(INFO)<<"this is createClassNameFunc\n";\
		return new className;\
	}\
};\
className##Helper className##helper;

REGISTRY(FileItem)
REGISTRY(ConsoleItem)


static void *createFileItemFunc2(){
	LOG(INFO)<<"this is createFileItemFunc2\n";
	return new FileItem;
}


int main() {

	google::InitGoogleLogging("MyReflect");
	FLAGS_logtostderr=1;


	FileItem* fileItemPtr= static_cast<FileItem*>(ClassFactory::getInstance().getItemObject("FileItem"));
	fileItemPtr->Print();
	delete fileItemPtr;

	LOG(INFO)<<"change createObjFunc\n";
	ClassFactory::getInstance().registItemObject("FileItem",createFileItemFunc2);
	fileItemPtr=static_cast<FileItem*>(ClassFactory::getInstance().getItemObject("FileItem"));
	fileItemPtr->Print();
	delete fileItemPtr;

	ConsoleItem* consoleItemPtr= static_cast<ConsoleItem*>(ClassFactory::getInstance().getItemObject("ConsoleItem"));
	consoleItemPtr->Print();
	delete consoleItemPtr;


	google::ShutdownGoogleLogging();
	return 0;
}