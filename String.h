#ifndef STRING_H
#define STRING_H

#include <string>

#include "Class.h"

class String:public Item
{
public:
	String();
	String(std::string data);//use for literals
	virtual ~String();
	virtual std::string print()const;
	virtual Item* elementAt(int index);
	virtual Item* clone()const;
	virtual void assignValue(std::string value);
private:
	std::string m_data;
};

#endif // STRING_H
