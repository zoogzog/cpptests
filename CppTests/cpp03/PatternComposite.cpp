#include "PatternComposite.h"

void CompositeObject::methodA()
{
	cout << "Draw an object" << endl;
}

void CompositeObjectCollection::methodA()
{
	cout << "Draw a complex object consisted of " << collection.size() << " objects" << endl;
}

void CompositeObjectCollection::add(CompositeObject * obj)
{
	collection.push_back(obj);
}