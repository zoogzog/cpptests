#include "TesterCPP03.h"

//========================================================================================
//---- TEST 001: Template instantiation implicit vs explicit
void TesterCPP03::test001()
{
	TemplateImplicit <int> templateINT(5);
	TemplateImplicit <double> templateDOUBLE(3.5);

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 001: Implicit vs explicit instantiation of a template" << endl;
	cout << "Implicit instantiation: " << endl;
	templateINT.displayData();
	templateDOUBLE.displayData();

	TemplateExplicit <int> templateExplicitINT(3);
	TemplateExplicit <bool> templateExplicitBOOL(true);

	cout << "Explicit instantiation: " << endl;
	templateExplicitINT.displayData();
	templateExplicitBOOL.displayData();

	cout << "Since explicit instantiation is done only for INT and BOOL the following:" << endl;
	cout << "TemplateExplicit <double> templateExplicitDOUBLE(3.5)" << " <--  will cause error" << endl;

}

//========================================================================================
//---- TEST 101: Design Pattern: Factory
void TesterCPP03::test101()
{
	PatternDeviceInterface * deviceA = PatternDeviceFactory::getDeviceInterface(PatternDeviceType::DEVICE_A);
	PatternDeviceInterface * deviceB = PatternDeviceFactory::getDeviceInterface(PatternDeviceType::DEVICE_B);

	deviceA->dataSet(1);
	deviceB->dataSet(1);

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 101: Design patterns - Interface & Factory" << endl;
	deviceA->dataPrint();
	deviceB->dataPrint();

}

//========================================================================================
//---- TEST 102: Design Pattern: Singleton
void TesterCPP03::test102()
{
	PatternSingleton * singletonA = PatternSingleton::getInstance();
	PatternSingleton * singletonB = PatternSingleton::getInstance();

	singletonA->dataSet(1543);

	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 102: Design patterns - Singleton" << endl;
	cout << "SingletonA: " << singletonA->dataGet() << endl;
	cout << "SingletonB: " << singletonB->dataGet() << endl;

}

//========================================================================================
//---- TEST 103: Design Pattern: Prototype
void TesterCPP03::test103()
{

	//---- The purpose of this test is to check that the Prototyping will reduce time of 
	//---- object generation
	std::vector <PatternPrototypeInterface *> devicelist;

	auto t1 = Clock::now();
	for (int k = 0; k < 100000; k++)
	{
		int rrand = rand() % 3;

		devicelist.push_back(PatternPrototypeFactory::createDeviceClone(rrand));
	}
	auto t2 = Clock::now();

	for (int k = 0; k < 100000; k++)
	{
	
		int rrand = rand() % 3;

		devicelist.push_back(PatternPrototypeFactory::createDeviceNew(rrand));
	}

	auto t3 = Clock::now();

	int delta1 = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	int delta2 = std::chrono::duration_cast<std::chrono::nanoseconds>(t3 - t2).count();
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 103: Design patterns - Prototype" << endl;
	cout << "Prototype test time: " << delta1 << endl;
	cout << "Factory test time: " << delta2 << endl;
	cout << "Speed up: " << (double)delta2 / delta1 << endl;
}

//========================================================================================
//---- TEST 104: Design Pattern: Builder
void TesterCPP03::test104()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 104: Design patterns - Builder" << endl;

	pcDesktop * pc;
	BuilderASUS pcbuilderASUS;
	BuilderDELL pcbuilderDELL;

	Director builderDirector;

	builderDirector.setBuilder(& pcbuilderASUS);
	pc = builderDirector.getDesktopPC();
	pc->specifications();

	builderDirector.setBuilder(&pcbuilderDELL);
	pc = builderDirector.getDesktopPC();
	pc->specifications();


}

//========================================================================================
//---- TEST 105: Design Pattern: Object pool

void TesterCPP03::test105()
{
	cout << "-------------------------------------------------------------------------" << endl;
	cout << "Test CPP03 105: Design patterns - Object pool" << endl;

	PatternObjectPool * opool = PatternObjectPool::getInstance();

	Resource * res1 = opool->resourceGet();
	Resource * res2 = opool->resourceGet();
	Resource * res3 = opool->resourceGet();
	//--- Can't create
	Resource * res4 = opool->resourceGet();
	if (!res4) { cout << "Resource is empty!" << endl; }
	
	opool->resourceReturn(res3);

	res4 = opool->resourceGet();
	if (res4) { cout << "Got new resource" << endl; }
}

//========================================================================================
//---- TEST 106: Design Pattern: Adapter
void TesterCPP03::test106()
{
	DeviceB * devb = new DeviceB();

	Adapter * adapter = new Adapter();
	adapter->setup(devb);

	InterfaceDeviceA * devba = adapter;

	cout <<"Adapter B->A [function_AAA]: "<< devba->function_AAA() << endl;
	cout <<"Adapter B->A [function_BBB]: " << devba->function_BBB() << endl;

}

//========================================================================================
//---- TEST 107: Design Pattern: Adapter
void TesterCPP03::test107()
{
	OSInterface * windows = new OSWindows();
	OSInterface * ubuntu = new OSUbuntu();

	Application * app1 = new NukeLauncher();
	Application * app2 = new MoonrocketLauncher();

	app1->setup(windows);
	app1->sendemail();
	app1->dosomething();

	app1->setup(ubuntu);
	app1->dosomething();

	app2->setup(ubuntu);
	app2->dosomething();
}

//========================================================================================
//---- TEST 108: Design Pattern: Composite
void TesterCPP03::test108()
{
	CompositeObject * obj = new CompositeObject();
	obj->methodA();

	CompositeObjectCollection collection;

	for (int k = 0; k < 5; k++)
	{
		CompositeObject * tobj = new CompositeObject();
		collection.add(tobj);
	}

	collection.methodA();

}

//========================================================================================
//---- TEST 109: Design Pattern: Decorator
void TesterCPP03::test109()
{
	SimpleChair * chairSimple = new SimpleChair();

	chairSimple->make();

	ClassyChair * chairClassy = new ClassyChair(chairSimple);
	FancyChair * chairFancy = new FancyChair(chairSimple);

	chairClassy->make();
	chairFancy->make();

	Table table;

	FancyTable<Table> tableFancy(4);
	tableFancy.make();
	tableFancy.breaktable();
}
//========================================================================================
//---- TEST 110: Design Pattern: Facade
void TesterCPP03::test110()
{
	examplefacade::Facade facade;

	cout << "Run facade: " << facade.execute() << endl;
}

//========================================================================================
//---- TEST 111: Design Pattern: Flyweight
void TesterCPP03::test111()
{
	GuiIconCollection collection;

	collection.initialize(10);

	collection.geticon(3)->draw(2, 2);

	collection.printactiveflyweights();
}

//========================================================================================
//---- TEST 112: Design Pattern: Proxy
void TesterCPP03::test112()
{
	exampleproxy::ObjectProxy obj(3);

	obj.method();
	obj->method();
}

void TesterCPP03::run(TestName03 testname)
{
	switch (testname)
	{
	case TEST001: test001(); break;
	case TEST101: test101(); break;
	case TEST102: test102(); break;
	case TEST103: test103(); break;
	case TEST104: test104(); break;
	case TEST105: test105(); break;
	case TEST106: test106(); break;
	case TEST107: test107(); break;
	case TEST108: test108(); break;
	case TEST109: test109(); break;
	case TEST110: test110(); break;
	case TEST111: test111(); break;
	case TEST112: test112(); break;
	}
}