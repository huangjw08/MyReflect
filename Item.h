//
// Created by root on 18-11-23.
//

#ifndef MYREFLECT_ITEM_H
#define MYREFLECT_ITEM_H

#include <string>

class Item{
public:
	Item(const std::string cname=""):className(cname){}
	virtual ~Item(){}
	virtual void Print()=0;

protected:
	std::string className;
};


#endif //MYREFLECT_ITEM_H
