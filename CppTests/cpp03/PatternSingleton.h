#pragma once

class PatternSingleton
{
private:
	int data;

	static PatternSingleton * instance;

	PatternSingleton();

public:
	static PatternSingleton * getInstance();

	void dataSet(int value);
	int dataGet();
};