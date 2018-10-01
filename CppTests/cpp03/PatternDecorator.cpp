#include "PatternDecorator.h"

//-----------------------------------------------
void SimpleChair::make()
{
	cout << "Make a simple chair" << endl;
}



ChairDecorator::ChairDecorator(int c, Chair * chair)
{
	this->decoratedChair = chair;
	color = c;
}

ClassyChair::ClassyChair(Chair * chair) : ChairDecorator(5, chair)
{
	
}

void ClassyChair::make()
{
	cout << "---- Make a CLASSY chair ----" << endl;
	this->decoratedChair->make();
	cout << "Color witht " << this->color << endl;
}

FancyChair::FancyChair(Chair * chair) : ChairDecorator(3, chair)
{

}

void FancyChair::make()
{
	cout << "---- Make a FANCY chair ----" << endl;
	this->decoratedChair->make();
	cout << "Color witht " << this->color << endl;
}

//-----------------------------------------------
void  Table::make()
{
	cout << "Make a simple table" << endl;
}

void Table::breaktable()
{
	cout << "Break the table" << endl;
}


template <typename T> FancyTable<T>::FancyTable(int c)
{
	color = c;
}

template <typename T> void FancyTable<T>::make()
{
	cout << "Make a fancy table with color " << color << endl;
}

//---- This is an explicit template
template class FancyTable<Table>;