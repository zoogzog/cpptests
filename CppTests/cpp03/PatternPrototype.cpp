#include "PatternPrototype.h"

#include <iostream>

using namespace std;

PatternPrototypeInterface * PrototypeA::clone()
{
	return new PrototypeA;
}

void PrototypeA::somemethod()
{
	cout << "Prototype A - method" << endl;
}

PatternPrototypeInterface * PrototypeB::clone()
{
	return new PrototypeA;
}

void PrototypeB::somemethod()
{
	cout << "Prototype B - method" << endl;
}

PatternPrototypeInterface * PrototypeC::clone()
{
	return new PrototypeA;
}

void PrototypeC::somemethod()
{
	cout << "Prototype C - method" << endl;
}

PatternPrototypeInterface * PatternPrototypeFactory::protolist[] = {new PrototypeA, new PrototypeB, new PrototypeC };

PatternPrototypeInterface * PatternPrototypeFactory::createDeviceClone(int type)
{
	return protolist[type];
}

PatternPrototypeInterface * PatternPrototypeFactory::createDeviceNew(int type)
{
	if (type == 0) return new PrototypeA;
	if (type == 1) return new PrototypeB;
	if (type == 2) return new PrototypeC;
}