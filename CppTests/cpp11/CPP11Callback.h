#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

namespace callback
{
	string generatestring(string data);

	string generatecomplexstring(string input, string(*func)(string));



	string example(int a, double b, string c);
	string examplecombined(int a, string(*func)(int, double, string));

	class Test001
	{
	public:
		static void run();
	};

	class Test002
	{
	public:
		static void run();
	};
}