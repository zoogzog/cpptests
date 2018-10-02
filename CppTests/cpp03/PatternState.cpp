#include "PatternState.h"

using namespace examplestate;

Object::Object()
{
	this->currentState = new StateOFF();
}

void Object::setstate(State * s)
{
	this->currentState = s;
}

void Object::methodON()
{
	this->currentState->methodON(this);
}

void Object::methodOFF()
{
	this->currentState->methodOFF(this);
}

void State::methodON(Object * obj)
{
	cout << "Base state ON " << endl;
}

void State::methodOFF(Object * obj)
{
	cout << "Base state OFF " << endl;
}

void StateON::methodOFF(Object * obj)
{
	cout << "ON calls OFF";
	obj->setstate(new StateOFF());
	delete this;
}

void StateOFF::methodON(Object * obj)
{
	cout << "OFF calls ON";
	obj->setstate(new StateOFF());
	delete this;
}