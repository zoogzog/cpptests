#include "PatternDeviceFactory.h"

PatternDeviceInterface * PatternDeviceFactory::getDeviceInterface(PatternDeviceType type)
{
	switch (type)
	{
	case DEVICE_A: return new PatternDeviceA();
	case DEVICE_B: return new PatternDeviceB();
	}
}