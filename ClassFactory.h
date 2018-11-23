//
// Created by root on 18-11-23.
//

#ifndef MYREFLECT_CLASSFACTORY_H
#define MYREFLECT_CLASSFACTORY_H


#include "Singleton.h"
#include <map>
#include <string>

typedef void* (*createObjFuncPtr)();

class ClassFactory: public Singleton<ClassFactory>{
public:

	void* getItemObject(const std::string &className);

	void registItemObject(const std::string &className,createObjFuncPtr ptr);

	~ClassFactory();

private:
	friend Singleton<ClassFactory>;
	ClassFactory(){}
	std::map<std::string,void*> factory;
};

#endif //MYREFLECT_CLASSFACTORY_H
