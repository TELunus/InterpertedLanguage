#include <iostream>
#include <sstream>
#include "Builtin.h"

Builtin::Builtin(Item* (*myAction)(ArgumentList&)):m_myAction(myAction)
{
	//
}

Builtin::~Builtin()
{
	//std::cout<<"<Builtin/>"<<std::endl;
}

Item* Builtin::run(ArgumentList& arguments)
{
	//std::cout<<"Running..."<<std::endl;
	Item* result = (*m_myAction)(arguments);
	//Item* cloned = result->clone();
	//std::cout<<"Finished!"<<std::endl;
	//delete result//do we want this?
	return result;
}

Item* Builtin::clone() const
{
	return new Builtin((*this));
}

std::string Builtin::print() const
{
	std::stringstream result;
	result<<"This is a builtin function, nothing to print"<<std::endl;
	return result.str();
}
