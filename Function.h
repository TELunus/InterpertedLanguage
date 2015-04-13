#ifndef FUNCTION_H
#define FUNCTION_H

#include "NameSpace.h"
#include "Command.h"

class Function: public NameSpace, public Command
{
public:
	virtual Item* run(ArgumentList& arguments,NameSpace* spaceToSearch);
	//virtual void add(const Item& toAdd,std::string subName);
	void append(Command* toAppend,ArgumentList& arguments);
	virtual Item* clone()const;
	virtual std::string print()const;

private:
	std::vector<Command*> m_commands;
	std::vector<ArgumentList> m_arguments;

};

#endif // FUNCTION_H
