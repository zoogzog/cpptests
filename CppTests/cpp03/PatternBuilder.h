#pragma once

#include <iostream>
#include <string>

using namespace std;

//-----------------------------------------------------------
//----- These are classes that are components of a bigger class
class pcKeyboard
{
public:
	string language;
};

class pcCPU
{
public:
	int id;
	string name;
};

class pcGPU
{
public:
	int id;
	string name;
};

class pcRAM
{
public:
	int size;
};

//-----------------------------------------------------------
//---- This class is composed from smaller classes

class pcDesktop
{
public:
	pcKeyboard * keyboard;
	pcCPU * cpu;
	pcGPU * gpu;
	pcRAM * ram;

	void specifications()
	{
		cout << "CPU: " << cpu->name << " serial=" << cpu->id << endl;
		cout << "GPU: " << gpu->name << " serial=" << gpu->id << endl;
		cout << "RAM: " << ram->size << "GB" << endl;
	}
};

//-----------------------------------------------------------
//---- This is an interface for all builder. Each individual builder 
//---- will build a computer with pre-defined specifications

class Builder
{
public:
	virtual pcKeyboard * buildKeyboard() = 0;
	virtual pcCPU * buildCPU() = 0;
	virtual pcGPU * buildGPU() = 0;
	virtual pcRAM * buildRAM() = 0;
};

//----- Custom builders
class BuilderDELL : public Builder
{
public:
	pcKeyboard * buildKeyboard();
	pcCPU * buildCPU();
	pcGPU * buildGPU();
	pcRAM * buildRAM();
};

class BuilderASUS : public Builder
{
public:
	pcKeyboard * buildKeyboard();
	pcCPU * buildCPU();
	pcGPU * buildGPU();
	pcRAM * buildRAM();
};

//-----------------------------------------------------------

class Director
{
private:
	Builder * builder;
public:

	void setBuilder(Builder * b);

	pcDesktop * getDesktopPC();
};
