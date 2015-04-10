#ifndef ITEM_H_STAGE_1
#define ITEM_H_STAGE_1

class Item;
#include "ArgumentList.h"

#endif // ITEM_H_STAGE_1
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

//class Item;

class Item
{
public:
	virtual ~Item();
	virtual Item* clone() const = 0;
	virtual std::string print() const = 0;
	virtual Item* access(std::string identifier);
	virtual void add(Item* toAdd,std::string name);
	virtual Item* dot(std::string subName);
	virtual Item* run(ArgumentList& arguments);
	virtual Item* elementAt(int index);
	virtual void assignValue(std::string value);
};

#endif
