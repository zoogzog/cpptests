#include "TesterCPP11.h"


void TesterCPP11::test001()
{
	int array[TesterCPP11::getint() + 1];

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 001: Generalized constant expressions." << endl;
	cout << "In array declaration now a function that returns constant expression can be used." << endl;
	cout << "Function returns " << TesterCPP11::getint() << ", elements in array - " << sizeof(array) / sizeof(array[0]) << endl;
}

void TesterCPP11::run()
{
	test001();
}