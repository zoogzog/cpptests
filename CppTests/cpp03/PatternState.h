#pragma once


#include <iostream>

using namespace std;

namespace examplestate
{

	class Object
	{
	private:
		//--- Here we do forward declaration
		class State * currentState;
	public:
		Object();
		void setstate(State * s);
		void methodON();
		void methodOFF();
	};

	//---- Basic state interface
	class State
	{
	public:
		virtual void methodON(Object * obj);
		virtual void methodOFF(Object * obj);
	};

	class StateON : public State
	{
	public:
		void methodOFF(Object * obj);
	};

	class StateOFF : public State
	{
	public:
		void methodON(Object * obj);
	};

}