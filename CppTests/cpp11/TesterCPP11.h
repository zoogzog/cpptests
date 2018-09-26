#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include "CPP11Utils.h"

using namespace std;

class TesterCPP11
{
private:

	static constexpr int getint() { return 10; }

	//--- TEST 001: Generalized constant expression
	void test001();
	//--- TEST 002: Initializer lists
	void test002();

public:
	void run();
};