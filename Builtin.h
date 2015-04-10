#ifndef BUILTIN_H
#define BUILTIN_H

#include "Command.h"

class Builtin:public Command
{
public:
	Builtin(Item* (*myAction) (ArgumentList&));
	virtual ~Builtin();
	virtual Item* run(ArgumentList& arguments);
	virtual Item* clone() const;
	virtual std::string print() const;
private:
	Item* (*m_myAction) (ArgumentList&);
};

#endif // BUILTIN_H
