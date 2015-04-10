#include <iostream>
#include "Item.h"

Item::~Item()
{
	//std::cout<<"<Item/>"<<std::endl;
}

Item* Item::access(std::string identifier)
{
	std::cout<<"nope!"<<std::endl;
	throw(std::string("Trying to access a subname of an item that isn't a namespace"));
	return nullptr;
}

void Item::add(Item* toAdd,std::string name)
{
	std::cout<<"invalid add attepmt"<<std::endl;
}

Item* Item::dot(std::string subName)
{
	std::cout<<"Invalid member access attempt"<<std::endl;
	return nullptr;
}

Item* Item::run(ArgumentList& arguments)
{
	std::cout<<"Tried to run non-command item"<<std::endl;
	return nullptr;
}

Item* Item::elementAt(int index)
{
	std::cout<<"Invalid sub element access attempt"<<std::endl;
	return nullptr;
}

void Item::assignValue(std::string value)
{
	std::cout<<"Invalid assignment"<<std::endl;
}
