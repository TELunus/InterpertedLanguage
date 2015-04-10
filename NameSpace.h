#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <string>
#include <map>

class NameSpace;

#include "Item.h"

class NameSpace: public virtual Item
{
public:
	//NameSpace(std::string ownName);
	NameSpace();
	virtual ~NameSpace();
	virtual void add(Item* toAdd,std::string subName);
	//virtual void add(const std::string& classIdentifier,const std::string& subName, const ArgumentList& arguments);
	virtual Item* dot(std::string subName);
	virtual Item* clone() const;
	virtual std::string print()const;
	virtual Item* access(std::string identifier);


private:
	//std::string m_ownName;
	std::map<std::string,Item*> m_subNames;
};



#endif
