#ifndef CLASS_H
#define CLASS_H

#include "NameSpace.h"

class Class: public NameSpace
{
public:
	virtual ~Class();
	virtual Item* clone() const;
	virtual std::string print() const;
};

#endif // CLASS_H
