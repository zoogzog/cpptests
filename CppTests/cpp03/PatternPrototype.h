#pragma once
//---- Prototype is like a factory, but the class creation procedure is heavy
//---- Thus if a lot of objects are created by a factory it will take lots of time.
//---- Prototype instead of doing what a normal factory does, pre-generates various types of possible
//---- classes and then outputs them.


//---- This is an interface that all prototypes share
class PatternPrototypeInterface
{
public:
	virtual PatternPrototypeInterface * clone() = 0;
	virtual void somemethod() = 0;
};

//---- This is a factory for generating class by their type
class PatternPrototypeFactory
{
public:
	//---- If we want to pass type as an element of an enum structure
	//---- Probably we need to use map instead of an array here
	static PatternPrototypeInterface * createDeviceClone(int type);
	static PatternPrototypeInterface * createDeviceNew(int type);
private:
	static PatternPrototypeInterface * protolist[3];
};


//---------- Different classes that share a common interface
class PrototypeA : public PatternPrototypeInterface
{
public:
	PatternPrototypeInterface * clone();
	void somemethod();
};

class PrototypeB : public PatternPrototypeInterface
{
public:
	PatternPrototypeInterface * clone();
	void somemethod();
};

class PrototypeC : public PatternPrototypeInterface
{
public:
	PatternPrototypeInterface * clone();
	void somemethod();
};

