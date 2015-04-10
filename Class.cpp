#include <iostream>
#include <sstream>
#include "Class.h"

Class::~Class()
{
	//std::cout<<"<Class/>"<<std::endl;
}

Item* Class::clone()const
{
	return new Class((*this));
}

std::string Class::print()const
{
	std::stringstream result;
	result<<"Printing class:"<<std::endl;
	result<<NameSpace::print();
	return result.str();
}
