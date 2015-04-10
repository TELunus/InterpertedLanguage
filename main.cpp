#include <iostream>

#include "Class.h"
#include "Builtin.h"
#include "String.h"
#include "Function.h"

Item* printItem(ArgumentList& myArgs);

Item* printItem(ArgumentList& myArgs)
{
	std::cout<<"PrintItem:"<<std::endl;
	std::cout<<myArgs.argumentAt(0)->print()<<std::endl;
	return nullptr;
}

Item* assignString(ArgumentList& myArgs);

Item* assignString(ArgumentList& myArgs)
{
	myArgs.argumentAt(0)->assignValue(myArgs.argumentAt(1)->print());
	return nullptr;
}


using namespace std;

int main()
{
    cout << "Begin testing" << endl;

    NameSpace testSpace;
    cout<<"test1:"<<std::endl<<std::endl;
    testSpace.print();
    testSpace.add(new NameSpace(),"subNameSpace");
    cout<<"test2:"<<std::endl<<std::endl;
    testSpace.print();
    cout<<"test3:"<<std::endl<<std::endl;
    testSpace.dot("subNameSpace")->print();
    testSpace.dot("subNameSpace")->add(new Class(),"testClass");
    cout<<"test4:"<<std::endl<<std::endl;
    testSpace.print();
    cout<<"test4.5"<<std::endl<<std::endl;
    testSpace.dot("subNameSpace")->dot("testClass")->print();
    cout<<"test5:"<<std::endl<<std::endl;
    testSpace.access("subNameSpace.testClass.print");
    cout<<"test6:"<<std::endl<<std::endl;
    testSpace.access("subNameSpace.testClass");
    cout<<"test7"<<std::endl<<std::endl;
    testSpace.access("subNameSpace.testClass")->print();


    Builtin printString(printItem);
    testSpace.add(new String("This is text\n"),"testString");
    testSpace.add(&printString,"print");
    ArgumentList argsToPrint(&testSpace);
    argsToPrint.add("testString","parameter");
	testSpace.access("print")->run(argsToPrint);
	std::cout<<"testing string assignment"<<std::endl;
	Builtin stringAssign(assignString);
	testSpace.add(&stringAssign,"stringAssign");
	testSpace.add(new String("Some more text"),"newValue");
	ArgumentList assignmentArgs(&testSpace);
	assignmentArgs.add("testString","parameter 1");
	assignmentArgs.add("newValue","parameter 2");
	testSpace.access("stringAssign")->run(assignmentArgs);
	testSpace.access("print")->run(argsToPrint);

	std::cout<<"Testing function functionality"<<std::endl;

	Function editAndPrint;
	editAndPrint.add(new String("Initial value"),"StringOne");
	ArgumentList funcTestArgs(&testSpace);
	testSpace.add(new String("Final value"),"TestStringTwo");
	funcTestArgs.add("TestStringTwo","StringTwo");
	ArgumentList funcAssignmentArgs(&editAndPrint);
	funcAssignmentArgs.add("StringOne","Uninportant1");
	funcAssignmentArgs.add("StringTwo","Uninportant2");
	ArgumentList funcPrintArgs(&editAndPrint);
	//todo: Argument list needs to determine namespace on name evaluation

//	testClass.add(Object("String",ArgumentList()),"testString");
//	testClass.add(Function("print",ArgumentList()));
//	ArgumentList tempAgrumentList();
//	tempAgrumentList.add("sting","self.testString");
//	testClass.dot("print").add(command("print",tempAgrumentList));
//	testClass.print();
//    testSpace.dot("subNameSpace").add(Object("testClass","testObject",ArgumentList()));
//    testSpace.dot("subNameSpace").print();
//    testSpace.dot("subNameSpace").dot("testObject").print();
//    testSpace.dot("subNameSpace").dot("testObject").dot("print").run(ArgumentList());

	std::cout<<"End testing!"<<std::endl;


    return 0;
}
