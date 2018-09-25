#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class TesterCPP11
{
private:

	static constexpr int getint() { return 10; }

	//--- Generalized constant expression
	void test001();

public:
	void run();
};