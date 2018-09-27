#pragma once

#include <list>
#include <iostream>

using namespace std;

class Resource
{
	int data;

public:
	Resource();

	int valueGet();
	void valueSet(int v);
	void reset();
};

//---- This is an object pool class that manages resources.
//---- The pool of resources is presented as a list of resources.
//---- This class is a singleton.

class PatternObjectPool
{
private:
	static PatternObjectPool * instance;
	PatternObjectPool();

	list <Resource *> resourcepool;

	const int POOL_MAX = 3;
	int resourceused;

public:
	static PatternObjectPool * getInstance();


	Resource * resourceGet();
	void resourceReturn(Resource * object);



};