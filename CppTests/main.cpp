#include <iostream>

#include "cpp11\TesterCPP11.h"
#include "cpp03\TesterCPP03.h"

using namespace std;

void main()
{
	cout << "Testing C++ 03/11/14/17 functionality" << endl;

	TesterCPP03 testercpp03;
	TesterCPP11 testercpp11;

	//testercpp11.run(TesterCPP11::TestName11::TEST001);
	testercpp03.run(TesterCPP03::TestName03::TEST107);

	//---- Prevent console from closing
	getchar();
}