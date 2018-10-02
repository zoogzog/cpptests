#include "PatternVisitor.h"

using namespace examplevisitor;

void ObjectA::accept(VisitorInterface * v)
{
	v->visit(this);
}

void ObjectA::randommethodA()
{
	cout << "random method A" << endl;
}

void VisitorA::visit(ObjectA * obj)
{
	cout << "Visitor A visits objet A " << endl;
}

void VisitorA::visit(ObjectB * obj)
{
	cout << "Visitor A visits objet B " << endl;
}


void ObjectB::accept(VisitorInterface * v)
{
	v->visit(this);
}

void ObjectB::randommehtodB()
{
	cout << "random method B" << endl;
}

void VisitorB::visit(ObjectA * obj)
{
	cout << "Visitor B visits objet A " << endl;
	
}


void VisitorB::visit(ObjectB * obj)
{
	cout << "Visitor B visits objet B " << endl;
}



