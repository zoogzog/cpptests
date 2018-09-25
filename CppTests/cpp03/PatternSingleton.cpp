#include "PatternSingleton.h"

PatternSingleton::PatternSingleton()
{
	data = 0;
}

PatternSingleton * PatternSingleton::getInstance()
{
	if (!instance)
	{
		instance = new PatternSingleton();
	}

	return instance;
}

int PatternSingleton::dataGet()
{
	return data;
}

void PatternSingleton::dataSet(int value)
{
	data = value;
}

PatternSingleton * PatternSingleton::instance = 0;