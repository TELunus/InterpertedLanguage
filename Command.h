#ifndef COMMAND_H
#define COMMAND_H

#include "Item.h"
#include "ArgumentList.h"

class Command: public virtual Item
{
public:
	virtual ~Command();
	virtual Item* run(ArgumentList& arguments,NameSpace* spaceToSearch) = 0;
};

#endif // COMMAND_H
