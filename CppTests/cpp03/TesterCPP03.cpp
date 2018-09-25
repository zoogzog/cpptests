#include "TesterCPP03.h"

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

void TesterCPP03::run()
{
	test001();

	test101();
}