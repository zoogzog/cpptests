#pragma once

#include <iostream>

using namespace std;

class CommandReceiver
{
public:
	void runCommandA();
	void runCommandB();
};

class CommandInterface
{
public:
	virtual void execute() = 0;
};

class CommandA : public CommandInterface
{
private:
	CommandReceiver * receiver;
public:
	CommandA(CommandReceiver * r);
	void execute();
};

class CommandB : public CommandInterface
{
private:
	CommandReceiver * receiver;
public:
	CommandB(CommandReceiver * r);
	void execute();
};


class CommandSender
{
private:
	CommandA * ca;
	CommandB * cb;
public:
	CommandSender(CommandA * coma, CommandB * comb);
	void runcommandA();
	void runcommandB();
};