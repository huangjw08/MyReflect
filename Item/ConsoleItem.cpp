//
// Created by root on 18-11-23.
//

#include "ConsoleItem.h"

ConsoleItem::ConsoleItem() :Item("ConsoleItem"){}


void ConsoleItem::Print() {
	LOG(INFO)<<className;
}
