#include <iostream>
#include <sstream>
#include <limits>
#include "NameSpace.h"


//NameSpace::NameSpace(std::string ownName):m_ownName(ownName),m_subNames()
//{
//	//
//}

NameSpace::NameSpace():m_subNames()
{
	//
}

NameSpace::~NameSpace()
{
	//std::cout<<"<Namespace>"<<std::endl;
	for(auto i = m_subNames.begin();i!=m_subNames.end();++i)
	{
		delete (i->second);
	}
	//std::cout<<"</Namespace>"<<std::endl;
}

void NameSpace::add(Item* toAdd,std::string subName)
{
	//todo error checking
	m_subNames.insert(std::pair<std::string,Item*>(subName,toAdd));
}

Item* NameSpace::dot(std::string subName)
{
	//todo error checking
	return m_subNames.at(subName);
}

Item* NameSpace::clone()const
{
	return new NameSpace((*this));
}

std::string NameSpace::print()const
{
	std::stringstream result;
	result<<"printing namespace:"<<std::endl;
	for(auto i = m_subNames.begin();i!=m_subNames.end();++i)
	{
		result<<"Name:"<<i->first<<std::endl;
		(i->second)->print();
	}
	return result.str();
}


Item* NameSpace::access(std::string identifier)
{
	Item* result = nullptr;
	std::stringstream input(identifier);
	std::string nextName;
	std::string remaining;
	std::string line;
	std::getline(input,nextName,'.');
	std::getline(input,remaining,';');
	//std::cout<<"NextName: "<<nextName<<std::endl;
	//std::cout<<"Remaining: "<<remaining<<std::endl;
	if(!m_subNames.count(nextName))
	{
		std::cout<<'"'<<nextName<<'"'<<" does not exist here"<<std::endl;
		std::cout<<"printing what is here:"<<std::endl;
		print();
	}
	else if(!remaining.empty())
	{//todo error checking
		result = m_subNames.at(nextName)->access(remaining);
	}
	else
	{
		//std::cout<<"Item found! It's my "<<nextName<<std::endl;
		result = m_subNames.at(nextName);
	}

	return result;
}
