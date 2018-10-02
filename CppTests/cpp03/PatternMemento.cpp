#include "PatternMemento.h"

using namespace examplememento;

int Memento::getstate()
{
	return this->state;
}

void Memento::setstate(int state)
{
	this->state = state;
}

void Object::methodadd()
{
	cout << "+2" << endl;
	data += 2;
}

void Object::methodmult()
{
	cout << "*2" << endl;
	data *= 2;
}

Memento * Object::saveState()
{
	Memento * outmeme = new Memento();
	outmeme->setstate(data);
	return outmeme;
}

void Object::reinstateState(Memento * mem)
{
	data = mem->getstate();
}

void Command::bindobject(Object * obj)
{
	this->obj = obj;
}

void Command::execute(Action action)
{
	this->mem = this->obj->saveState();
	(this->obj->*action)();
}

void  Command::revert()
{
	cout << "Revert changes" << endl;
	this->obj->reinstateState(this->mem);
}