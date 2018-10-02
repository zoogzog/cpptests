#pragma once

#include <iostream>

using namespace std;

namespace examplememento
{

	class Memento
	{
	private:
		friend class Object;

		int state;
	public:
		int getstate();
		void setstate(int state);
	};

	class Object
	{
	public:
		int data = 0;

		void methodadd();
		void methodmult();

		Memento * saveState();
		void reinstateState(Memento * mem);
	};

	class Command
	{
	private:
		Memento * mem;
		Object * obj;
	public:
		typedef void(Object::* Action)();

		void bindobject(Object * obj);
		void execute(Action action);
		void revert();
	};

}