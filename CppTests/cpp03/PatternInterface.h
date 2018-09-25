#pragma once

//---- This is an interface implemented as an abstract class 
class PatternDeviceInterface
{

protected: 

	int data;

public:
	virtual int dataGet() = 0;
	virtual void dataSet(int d) = 0;
	virtual void dataPrint() = 0;
};