#pragma once

#include <iostream>
#include "PatternDeviceA.h"
#include "PatternDeviceB.h"
#include "PatternInterface.h"

using namespace std;

enum PatternDeviceType {DEVICE_A, DEVICE_B};

class PatternDeviceFactory
{
public:
	static PatternDeviceInterface * getDeviceInterface(PatternDeviceType type);
};
