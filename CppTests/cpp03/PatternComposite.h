#pragma once


#include <iostream>
#include <list>

using namespace std;

class CompositeInterface
{
public:
	virtual void methodA() = 0;
};

//---- Object implements the defined interface
class CompositeObject: public CompositeInterface
{
private:
	int data;
public:
	void methodA();
};

//---- Collection of objects share the same interface as the object itseld
class CompositeObjectCollection : public CompositeInterface 
{
private:
	list <CompositeObject * > collection;

public:
	void methodA();
	void add(CompositeObject * obj);
};