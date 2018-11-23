//
// Created by root on 18-11-23.
//

#include "ClassFactory.h"
#include <glog/logging.h>

namespace RF{

void *ClassFactory::getItemObject(const std::string &className) {
	auto iter=factory.find(className);
	if(iter!=factory.end()){
		return (*(iter->second))();
	}else{
		LOG(ERROR)<<"this className has not corresponding createObjFuncPtr yet\n";
		return nullptr;
	}
}



void ClassFactory::registItemObject(const std::string &className, createObjFuncPtr ptr) {
	auto iter=factory.find(className);
	if(iter!=factory.end()){
		LOG(WARNING)<<"please make sure you have already delete previously ObjInstancePtr\n";
		iter->second=ptr;
	}else{
		factory.insert(std::make_pair(className,ptr));
	}
}

ClassFactory::~ClassFactory() {}

}


