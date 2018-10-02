#include "PatternResponsibilityChain.h"

HandlerBase::HandlerBase()
{
	this->handlernext = 0;
}

void HandlerBase::nextSet(HandlerBase * next)
{
	this->handlernext = next;
}

void HandlerBase::nextAdd(HandlerBase * next)
{
	if (this->handlernext == 0)
	{
		this->handlernext = next;
	}
	else
	{
		this->handlernext->nextAdd(next);
	}
}

void HandlerBase::processevenet(int i)
{
	if (this->handlernext != 0)
	{
		this->handlernext->processevenet(i);
	}
	else
	{
		cout << "CHAIN END " << endl;
	}
}

void CustomHandlerA::processevenet(int i)
{
	if (i == 1) { cout << "Handler A handled the event" << endl;  }
	else { cout << " A->NEXT ";  HandlerBase::processevenet(i); }
}

void CustomHandlerB::processevenet(int i)
{
	if (i == 2) { cout << "Handler B handled the event" << endl; }
	else { cout << " B->NEXT "; HandlerBase::processevenet(i); }
}

void CustomHandlerC::processevenet(int i)
{
	if (i == 3) { cout << "Handler C handled the event" << endl; }
	else { cout << " C->NEXT "; HandlerBase::processevenet(i); }
}

