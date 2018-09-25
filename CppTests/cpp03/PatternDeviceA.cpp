#include "PatternDeviceA.h"

PatternDeviceA::PatternDeviceA()
{

}

int PatternDeviceA::dataGet()
{
	return data + AX1;
}

void PatternDeviceA::dataSet(int d)
{
	data = d + AX2;
}

void PatternDeviceA::dataPrint()
{
	cout << "DeviceA: [" << AX1 << "," << AX2 << "] d=" << data << endl;
}