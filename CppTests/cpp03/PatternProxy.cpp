#include "PatternProxy.h"

using namespace exampleproxy;

void Object::method()
{
	cout << "Method call on object" << endl;
}

Object::Object(int value)
{
	data = value;
}

ObjectProxy::ObjectProxy(int value)
{
	obj = new Object(value);
	valueA = value + 1;
	valueB = value - 1;
}

Object * ObjectProxy::operator->()
{
	return obj;
}

void ObjectProxy::method()
{
	cout << "Method call on proxy" << endl;
}

ObjectProxy::~ObjectProxy()
{
	delete obj;
}
