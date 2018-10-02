#include "PatternCommand.h"


void CommandReceiver::runCommandA()
{
	cout << "Receiver runs command A" << endl;
}

void CommandReceiver::runCommandB()
{
	cout << "Receiver runs command B" << endl;
}

CommandA::CommandA(CommandReceiver * r)
{
	this->receiver = r;
}

void CommandA::execute()
{
	this->receiver->runCommandA();
}

CommandB::CommandB(CommandReceiver * r)
{
	this->receiver = r;
}


void CommandB::execute()
{
	this->receiver->runCommandB();
}

CommandSender::CommandSender(CommandA * ca, CommandB * cb)
{
	this->ca = ca;
	this->cb = cb;
}

void CommandSender::runcommandA()
{
	ca->execute();
}

void CommandSender::runcommandB()
{
	cb->execute();
}


