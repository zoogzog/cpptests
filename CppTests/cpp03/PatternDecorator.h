#pragma once

#include <iostream>
#include <string>

using namespace std;

//-----------------------------------------------
//----- Example of a dynamic decorator
//----- Runtime composable decorator - requires to be 

class Chair
{
public:
	virtual void make() = 0;

};

class SimpleChair : public Chair
{
public:
	void make();

};


class ChairDecorator : public  Chair
{
protected:
	Chair * decoratedChair;
	int color = 0;
public: 
	ChairDecorator(int c, Chair * chair);

	virtual void make() = 0;
};

class ClassyChair : public ChairDecorator
{
public:
	ClassyChair(Chair * ch);

	void make() override;
};

class FancyChair : public ChairDecorator
{
public:
	FancyChair(Chair * ch);

	void make() override;
};

//-----------------------------------------------
//----- Example of a static decorator that uses templates
//----- This approach works in c++ cause class can inherit a template


struct Table
{
public:
	void make();
	void breaktable();
};

template <typename T> class FancyTable : public T
{
	int color = 0;
public:
	FancyTable(int c);
	void make();
};