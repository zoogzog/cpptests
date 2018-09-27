#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <typeinfo>

using namespace std;

//---- std::placeholders are needed for bind functionality
using namespace std::placeholders;

//========================================================================================
//------------- TEST: INITIALIZER LISTS
//---- This allows to initialize vecotrs and arrays using initializer lists

class ClassInitializerList
{

private:
	//---- Some data here
	vector<int> v;
	int x[4];

public:
	//---- These constructors allow to initialize with passing parameters  via {a, b, c}
	ClassInitializerList(std::initializer_list<int> l) { v = l; }
	ClassInitializerList() : x{ 0, 1, 2, 3 } {};
	void print() 
	{
		string out = "";
		for (int k = 0; k < v.size(); k++)
		{
			out.append(std::to_string(v.at(k)));
			out.append(" ");
		}

		cout << out << endl;

		for (int p = 0; p < 4; p++)
		{
			cout << x[p] << " ";
		}
		cout << endl;
	}
};

//========================================================================================
//------------- TEST: DELETE FUNCTIONS

class TestDelete
{
	int x;
public:
	TestDelete() { x = 0; }

	TestDelete(const TestDelete & td) = delete;

	TestDelete(int xx) : x(xx) { }
	TestDelete(double xx) = delete;
};

//========================================================================================
//------------- TEST: BIND

int bind_add(int op1, int op2);
bool bind_isstringequal(string op1, string op2);
int bind_findstring(string query);

//========================================================================================
//------------- TEST: AUTO

string auto_function001();

//========================================================================================
//------------- TEST: VARIADIC TEMPLATE

int vtemplatesum();

template<typename T, typename ... Arguments> int vtemplatesum(T first, Arguments ... arglist)
{

	if (string(typeid(first).name()) == "int")
	{
		cout << first << endl;
		return (int)first + vtemplatesum(arglist ...);
	}

	return 0;

}

