#include "TesterCPP11.h"

//========================================================================================
//---- TEST 001: Generalized constant expressions
void TesterCPP11::test001()
{
	int array[TesterCPP11::getint() + 1];

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 001: Generalized constant expressions." << endl;
	cout << "In array declaration now a function that returns constant expression can be used." << endl;
	cout << "Function returns " << TesterCPP11::getint() << ", elements in array - " << sizeof(array) / sizeof(array[0]) << endl;
}

//========================================================================================
//---- TEST 002: Initializer lists
void TesterCPP11::test002()
{
	ClassInitializerList test = { 1, 2, 3 };
	ClassInitializerList test2 = { 1,2,3,4 };

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 002: Initializer lists" << endl;

	test.print();
	test2.print();

	vector <int> keke{ 1, 2, 3, 4, 5 };
}

//========================================================================================
//---- TEST 003: delete keyword
void TesterCPP11::test003()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 003: delete keyword" << endl;

	TestDelete tdl1{ 2 };
	
	//TestDelete tdl2(tdl1);   //<--- This will cause a compiler error this function is deleted
	// TestDelete tdl2{ 3.5 }; //<--- This will cause a compiler error this function is deleted

}

//========================================================================================
//---- TEST 004: Bind
void TesterCPP11::test004()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 004: bind" << endl;

	auto functionadd = std::bind(&bind_add, 10, _1);

	cout << "Add function f=" << bind_add(1, 3) << endl;
	cout << "Bind function with first=10 f=" << functionadd(3) << endl;
	cout << "Bind algorithm xxx f=" << bind_findstring("xxx") << endl;
	cout << "Bind algorithm ccc f=" << bind_findstring("ccc") << endl;

	auto func = &auto_function001;

	cout << "Auto function: " << func() << endl;
}

//========================================================================================
//---- TEST 005: Variadic template functions

void TesterCPP11::test005()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP11 005: Variadic template" << endl;
//	cout << templatesum(3, 3.5, 4.5, 6, 7) << endl;
	cout << "end: " <<vtemplatesum(2, 3.4, "aaa") << endl;
}

//---- TEST 006: Smart pointers
void TesterCPP11::test006()
{
	smrtptr::Test001::run();
	smrtptr::Test002::run();
}

//---- TEST 007: callbacks and function pointers, lambda
void TesterCPP11::test007()
{
	callback::Test001::run();
	callback::Test002::run();
}

//---- TEST 008: Multi-threading
void TesterCPP11::test008()
{
	examplethread::ThreadRunner::run();
	examplethread::ThreadRunner::runfuture();
}

void TesterCPP11::run(TestName11 testname)
{
	switch (testname)
	{
		
	case TEST001: test001(); break;
	case TEST002: test002(); break;
	case TEST003: test003(); break;
	case TEST004: test004(); break;
	case TEST005: test005(); break;
	case TEST006: test006(); break;
	case TEST007: test007(); break;
	case TEST008: test008(); break;
	}
}