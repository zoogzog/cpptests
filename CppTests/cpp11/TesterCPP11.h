#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <typeinfo>

#include "CPP11Utils.h"
#include "CPP11Smrtptr.h"
#include "CPP11Callback.h"
#include "CPP11Thread.h"

using namespace std;
using namespace std::placeholders;



class TesterCPP11
{
private:

	static constexpr int getint() { return 10; }

	//---------------------- UTILITIES  ----------------------
	//---- TEST 001: Generalized constant expression
	void test001();
	//---- TEST 002: Initializer lists
	void test002();
	//---- TEST 003: Delete keyword
	void test003();
	//---- TEST 004: Bind 
	void test004();
	//---- TEST 005: Variadic template
	void test005();

	//-------------------- SMART POINTERS  -------------------
	void test006();

	//-------------------- CALLBACKS -------------------
	void test007();

	//-------------------- THREADING -------------------
	void test008();

public:
	enum TestName11 
	{ 
		TEST001, TEST002, TEST003, TEST004, TEST005, TEST006,
		TEST007, TEST008
	};

	void run(TestName11 testname);
};