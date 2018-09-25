#include "PatternDeviceB.h"

PatternDeviceB::PatternDeviceB()
{

}

int PatternDeviceB::dataGet()
{
	return data + BX1;
}

void PatternDeviceB::dataSet(int d)
{
	data = d + BX2;
}

void PatternDeviceB::dataPrint()
{
	cout << "DeviceB: [" << BX1 << "," << BX2 << "] d=" << data << endl;
}