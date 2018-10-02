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
#include "PatternAdapter.h"
#include "PatternBridge.h"
#include "PatternComposite.h"
#include "PatternDecorator.h"
#include "PatternFacade.h"
#include "PatternFlyweight.h"
#include "PatternProxy.h"
#include "PatternResponsibilityChain.h"
#include "PatternCommand.h"
#include "PatternMemento.h"
#include "PatternState.h"
#include "PatternVisitor.h"

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
	//---- TEST106 Pattern: Adapter
	void test106();
	//---- TEST107 Pattern: Bridge
	void test107();
	//---- TEST108 Pattern: Composite
	void test108();
	//---- TEST109 Pattern: Decorator
	void test109();
	//---- TEST110 Pattern: Facade
	void test110();
	//---- TEST111 Pattern: Flyweight
	void test111();
	//---- TEST112 Pattern: Proxy
	void test112();
	//---- TEST113 Pattern: Chain of Responsibility
	void test113();
	//---- TEST114 Pattern: Command
	void test114();
	//---- TEST115 Pattern: Memento
	void test115();
	//---- TEST116 Pattern: State
	void test116();
	//---- TEST117 Pattern: Visitor
	void test117();

public:
	enum TestName03 
	{ 
		TEST001, TEST101, TEST102, TEST103, TEST104, TEST105, 
		TEST106, TEST107, TEST108, TEST109, TEST110, TEST111, 
		TEST112, TEST113, TEST114, TEST115, TEST116, TEST117
	};

	void run(TestName03 testname);
};
