#include "PatternBridge.h"


void OSWindows::shellcommand(string command)
{
	cout << "Windows is running command " << command << endl;
}

void OSUbuntu::shellcommand(string command)
{
	cout << "Ubuntu is running command" << command << endl;
}

void NukeLauncher::dosomething()
{
	if (os)
	{
		os->shellcommand("KILL ALL HOOMANS");
	}
}

void NukeLauncher::sendemail()
{
	cout << "Mail sent: Launching nukes" << endl;
}

void MoonrocketLauncher::sendemail()
{
	cout << "Mail sent: Launching Apollo rocket" << endl;
}

void MoonrocketLauncher::dosomething()
{
	if (os)
	{
		os->shellcommand("GROUND CONTROL TO MAJOR TOM");
	}
}

void Application::setup(OSInterface * os)
{
	this->os = os;
}