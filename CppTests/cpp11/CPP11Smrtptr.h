#pragma once

#include <iostream>
#include <memory>

using namespace std;

namespace smrtptr
{
	struct StructureA
	{
		int x;
		int y;
		int z;

		StructureA() { cout << "ctor" << endl; }
		~StructureA() { cout << "dtor" << endl;  }
	};



	class Test001
	{
	public:
		static void run();
	};

	class Test002
	{
	public:
		static void run();
	};
}
