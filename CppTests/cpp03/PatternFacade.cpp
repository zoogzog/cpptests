#include "PatternFacade.h"

using namespace examplefacade;

int ObjectA::executeA()
{
	dataA += 10;

	return dataA;
}

int ObjectB::executeB()
{
	dataB += 20;

	return dataB;
}

int Facade::execute()
{
	int ra = obja.executeA();
	int rb = objb.executeB();

	return ra + rb;
}