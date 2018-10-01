#include "PatternFlyweight.h"

GuiIcon::GuiIcon(string name)
{
	this->name = name;
}

void GuiIcon::draw(int x, int y)
{
	cout << "Draw icon " << name << " at " << x << " " << y << endl;
}

string GuiIcon::getName()
{
	return this->name;
}


GuiIcon * GuiIconCollection::geticon(int id)
{
	if (id >= 0 && id < collection.size())
	{
		return & collection.at(id);
	}

	return 0;
}

void GuiIconCollection::initialize(int value)
{
	for (int i = 0; i < value; i++)
	{
		collection.push_back(GuiIcon(to_string(i)));
	}
}

void GuiIconCollection::printactiveflyweights()
{
	for (int k = 0; k < collection.size(); k++)
	{
		cout << "Icon " << collection.at(k).getName() << " is active" << endl;
	}
}

vector <GuiIcon>  GuiIconCollection::collection;