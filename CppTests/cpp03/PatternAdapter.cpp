#include "PatternAdapter.h"

int DeviceA::function_AAA()
{
	return 1543;
}

int DeviceA::function_BBB()
{
	return 1984;
}

double DeviceB::function_XXX()
{
	return 3.14;
}

string DeviceB::function_YYY()
{
	return "cake-is-a-lie";
}

void Adapter::setup(InterfaceDeviceB * device)
{
	this->device = device;
}

int Adapter::function_AAA()
{
	return (int) this->device->function_XXX();
}

int Adapter::function_BBB()
{
	return this->device->function_YYY().length();
}