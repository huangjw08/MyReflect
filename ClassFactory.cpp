//
// Created by root on 18-11-23.
//

#include "ClassFactory.h"

void *ClassFactory::getItemObject(const std::string &className) {
	auto iter=factory.find(className);
	if(iter!=factory.end()){
		return iter->second;
	}else{
		printf("this className has not corrsponding createObjFuncPtr yet\n");
		return nullptr;
	}

}


void ClassFactory::registItemObject(const std::string &className, createObjFuncPtr ptr) {
	auto iter=factory.find(className);
	if(iter!=factory.end())
	{
		//原本factory中已经存在了，需要先delete obj_ptr,再重新new 一个
		delete iter->second;
		iter->second=(*ptr)();
	}
	else{
		factory.insert(std::make_pair(className,(*ptr)()));
	}
}


ClassFactory::~ClassFactory() {
	for(auto &item:factory){
		if(item.second){
			delete item.second;
		}
	}
}
