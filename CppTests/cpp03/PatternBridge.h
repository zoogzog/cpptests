#pragma once

#include <iostream>
#include <string>

using namespace std;


//------------------------------------------------------------------------
//* https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns#Bridge

/* Implementor*/
class OSInterface
{
public:
	virtual void shellcommand(string command) = 0;
};

/* Concrete ImplementorA*/
class OSWindows : public OSInterface
{
public:
	void shellcommand(string command);
};

/* Concrete ImplementorB*/
class OSUbuntu : public OSInterface
{
public:
	void shellcommand(string command);
};

//------------------------------------------------------------------------

class Application
{
protected:
	OSInterface * os;
public:
	void setup(OSInterface * os);
	virtual void sendemail() = 0;
	virtual void dosomething() = 0;
};

class NukeLauncher : public Application
{
public:
	void sendemail();
	void dosomething();
};

class MoonrocketLauncher : public Application
{
public:
	void sendemail();
	void dosomething();
};