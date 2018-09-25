#pragma once

#include <iostream>

#include "TemplateImplicit.h"
#include "TemplateExplicit.h"
#include "PatternDeviceFactory.h"
#include "PatternSingleton.h"


using namespace std;

class TesterCPP03
{
private:

	//---- Template instantiation IMPLICIT vs EXPLICIT
	void test001();

	//---- TEST101 Pattern: FACTORY & INTERFACE
	void test101();
	//---- TEST102Pattern: SINGLETON
	void test102();

public:
	void run();
};
