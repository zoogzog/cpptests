#pragma once

#include <iostream>
#include <chrono>
#include <vector>

#include "TemplateImplicit.h"
#include "TemplateExplicit.h"
#include "PatternDeviceFactory.h"
#include "PatternSingleton.h"
#include "PatternPrototype.h"
#include "PatternBuilder.h"
#include "PatternObjectPool.h"

typedef std::chrono::high_resolution_clock Clock;

using namespace std;



class TesterCPP03
{
private:

	//---- Template instantiation IMPLICIT vs EXPLICIT
	void test001();

	//---- TEST101 Pattern: FACTORY & INTERFACE
	void test101();
	//---- TEST102 Pattern: SINGLETON
	void test102();
	//---- TEST103 Pattern: Prototype
	void test103();
	//---- TEST104 Pattern: Builder
	void test104();
	//---- TEST105 Pattern: Object pool
	void test105();


public:
	enum TestName03 { TEST001, TEST101, TEST102, TEST103, TEST104, TEST105 };

	void run(TestName03 testname);
};
