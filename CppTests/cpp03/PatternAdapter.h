#pragma once

#include <iostream>
#include <string>

using namespace std;

//-----------------------------------------------------------------
//---- Let's create an adapter between DeviceA interface and DeviceB interface

class InterfaceDeviceA
{
public:
	virtual int function_AAA() = 0;
	virtual int function_BBB() = 0;
};

class InterfaceDeviceB
{
public:
	virtual double function_XXX() = 0;
	virtual string function_YYY() = 0;
};

//---- Some devices
class DeviceA : public InterfaceDeviceA
{
public:
	int function_AAA();
	int function_BBB();
};

class DeviceB : public InterfaceDeviceB
{
public:
	double function_XXX();
	string function_YYY();
};


//---- Adapter from DeviceB (source) to DeviceA (desired target)
class Adapter : public InterfaceDeviceA
{
private:
	InterfaceDeviceB * device;

public:
	void setup(InterfaceDeviceB * device);

	int function_AAA();
	int function_BBB();
};