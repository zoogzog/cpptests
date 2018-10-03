#include "CPP11Callback.h"

using namespace callback;

string callback::generatestring(string data)
{
	return data + "XXX";
}

string callback::generatecomplexstring(string input, string(*func)(string))
{
	return input + "BBB" + func(input);
}

string callback::example(int a, double b, string c)
{
	return to_string(a) + to_string(b) + c;
}

string callback::examplecombined(int a, string(*func)(int, double, string))
{
	return "output-" + func(a, 10, "!!!");
}

void callback::Test001::run()
{
	cout << generatecomplexstring("-AAA-", &generatestring) << endl;
	cout << examplecombined(10, &example) << endl;
}

void callback::Test002::run()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	int var = 10;

	//---- Variable 'var' and 'arr' can be accessed read & write
	for_each(arr, arr + 5, [&](int x) { var += x; });

	cout << "Lambda1: " << var << endl;

	//---- Variable 'var' and 'arr' can be accessed only readonly
	for_each(arr, arr + 5, [=](int x) { x = var; });

	cout << "Lambda2: " << arr[0] << " " << arr[1] << endl;

	//---- Vairable 'var' can not be accessed, arr is not changed
	for_each(arr, arr + 5, [](int x) {  x = x * 2; });

	cout << "Lambda3: " << arr[0] << " " << arr[1] << endl;

	//------------------------------------------------

	string msg = "message";
	int value = 10;

	auto func = [msg, value]() mutable { msg = "heehehe"; };
	func();
	cout << msg << endl;
	auto func1 = [&msg, value]() { msg = to_string(value) + " hehe"; };
	func1();
	cout << msg << endl;

}