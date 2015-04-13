#include <sstream>

#include "Function.h"

Item* Function::run(ArgumentList& arguments,NameSpace* spaceToSearch)
{
	NameSpace instanceNamespace(*this);
	for(unsigned int i = 0;i<arguments.size();i++)
	{
		instanceNamespace.add(arguments.argumentAt(spaceToSearch,i),arguments.nameAt(i));
	}
	for(unsigned int i = 0;i<m_commands.size();i++)
	{
		//set namespace to search
		m_commands.at(i)->run(m_arguments.at(i),spaceToSearch);//redo argument system
	}
	return instanceNamespace.access("result");
}

Item* Function::clone() const
{
	return new Function((*this));
}

std::string Function::print() const
{
	std::stringstream result;
	result<<"Function:"<<std::endl;
	for(unsigned int i = 0;i<m_commands.size();i++)
	{
		result<<m_commands.at(i)->print()<<std::endl;
	}
	return result.str();
}

void Function::append(Item* toAppend,ArgumentList& arguments)
{
	m_commands.push_back(toAppend);
	m_arguments.push_back(arguments);
}
