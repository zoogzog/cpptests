#pragma once

#include <iostream>

using namespace std;

class HandlerBase
{
private:
	//---- Next handler to be responsible of handling an event
	HandlerBase * handlernext;
public:
	HandlerBase();

	//---- Set the next handler in the chain
	void nextSet(HandlerBase * next);
	//---- Add a new handler to the chain
	void nextAdd(HandlerBase * next);

	//---- This will handler an event
	virtual void processevenet(int i);
};


class CustomHandlerA : public HandlerBase
{
public:
	void processevenet(int i);
};

class CustomHandlerB : public HandlerBase
{
public:
	void processevenet(int i);
};

class CustomHandlerC : public HandlerBase
{
public:
	void processevenet(int i);
};
