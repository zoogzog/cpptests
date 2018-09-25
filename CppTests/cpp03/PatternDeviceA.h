#pragma once

#include <iostream>

#include "PatternInterface.h"

using namespace std;

class PatternDeviceA : public PatternDeviceInterface
{
private:

	const int AX1 = 3;
	const int AX2 = 6;

public:
	PatternDeviceA();

	int dataGet();
	void dataSet(int d);
	void dataPrint();

};