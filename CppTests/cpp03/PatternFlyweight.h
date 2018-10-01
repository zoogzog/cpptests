#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//-------------------------------------------------
//---- This is a Flyweight
class GuiIcon
{

private:
	//---- These are intrinsic variables
	int width = 0; int height = 0;
	string name = "";

public:

	GuiIcon(string name);
	string getName();

	//---- Coordinate parameters x, y are extrinsic 
	void draw(int x, int y);
};

//-------------------------------------------------
//---- This is a Flyweight factory, look it is static!
class GuiIconCollection
{
private:
	//---- Collection of Icons
	static vector <GuiIcon> collection;

public:
	static void initialize(int value);
	static GuiIcon * geticon(int id);
	static void printactiveflyweights();
};

