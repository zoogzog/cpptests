#pragma once

#include <iostream>

using namespace std;


namespace examplefacade
{
	class ObjectA
	{
	private:
		int dataA = 0;
	public:
		int executeA();
	};

	class ObjectB
	{
	private:
		int dataB = 1;
	public:
		int executeB();
	};

	class Facade
	{
	private:
		ObjectA obja;
		ObjectB objb;
	public:
		int execute();
	};

}