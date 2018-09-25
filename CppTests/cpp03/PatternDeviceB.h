#pragma once

#include <iostream>

#include "PatternInterface.h"

using namespace std;

class PatternDeviceB : public PatternDeviceInterface
{
	const int BX1 = 5;
	const int BX2 = 10;

public:
	PatternDeviceB();

	int dataGet();
	void dataSet(int d);
	void dataPrint();
		
};
