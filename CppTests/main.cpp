#include <iostream>

#include "cpp11\TesterCPP11.h"
#include "cpp03\TesterCPP03.h"

using namespace std;

void main()
{
	cout << "Testing C++ 03/11/14/17 functionality" << endl;

	TesterCPP03 testercpp03;
	testercpp03.run();

	TesterCPP11 testercpp11;
	testercpp11.run();


	//---- Prevent console from closing
	getchar();
}