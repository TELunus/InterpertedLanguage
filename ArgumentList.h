#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <vector>

class ArgumentList;

#include "NameSpace.h"

class ArgumentList
{
public:
    ArgumentList(NameSpace* myNamespace);
    ArgumentList(const ArgumentList& other);
    virtual ~ArgumentList();
    void add(std::string argument,std::string subName);
    unsigned int size()const;
    std::string nameAt(unsigned int i);
    Item* argumentAt(unsigned int i);
private:
	NameSpace* m_myNamespace;
	std::vector<std::string> m_arguments;
	std::vector<std::string> m_names;

};


#endif // ARGUMENTLIST_H
