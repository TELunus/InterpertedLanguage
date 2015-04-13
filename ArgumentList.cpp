#include "ArgumentList.h"

ArgumentList::ArgumentList():m_arguments(),m_names()
{
	//
}

ArgumentList::ArgumentList(const ArgumentList& other):m_arguments(),m_names()
{
	for (unsigned int i = 0;(i<other.m_arguments.size())&&(i<other.m_names.size());i++)
	{
		m_arguments.push_back(other.m_arguments.at(i));
		m_names.push_back(other.m_names.at(i));
	}
}

ArgumentList::~ArgumentList()
{
	//std::cout<<"<Argumentlist>"<<std::endl;
	for(unsigned int i = 0;i<m_arguments.size();i++)
	{
		//delete (m_arguments.at(i));
	}
	//std::cout<<"</Argumentlist>"<<std::endl;
}

void ArgumentList::add(std::string argument,std::string subName)
{
	//m_arguments.push_back(toAdd->clone());
	m_arguments.push_back(argument);
	m_names.push_back(subName);
}

unsigned int ArgumentList::size()const
{
	unsigned int result = m_names.size();
	if(m_arguments.size()<m_names.size())
	{
		result = m_arguments.size();
	}
	return result;
}

std::string ArgumentList::nameAt(unsigned int i)
{
	return m_names.at(i);
}

Item* ArgumentList::argumentAt(NameSpace* spaceToSearch,unsigned int i)
{
	return spaceToSearch->access(m_arguments.at(i));
	//return m_arguments.at(i);
}
