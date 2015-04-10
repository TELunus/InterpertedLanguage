#include <iostream>
#include <sstream>
#include "String.h"

String::String():m_data()
{
	//AddMembers
}

String::String(std::string data):m_data(data)
{
	//
}

String::~String()
{
	//std::cout<<"<String/>"<<std::endl;
}

std::string String::print()const
{
	std::stringstream result;
	//result<<"Printing string: '"<<m_data<<"'"<<std::endl;
	result<<m_data;
	return result.str();
}

Item* String::elementAt(int index)
{
	//std::string result("");
	const auto result = std::string(1, m_data.at(index));
	return new String(result);
}

Item* String::clone()const
{
	return new String((*this));
}

void String::assignValue(std::string value)
{
	m_data=value;
}
