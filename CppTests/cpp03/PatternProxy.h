#pragma once


#include <iostream>

using namespace std;

namespace exampleproxy
{
	class Interface
	{
	public:
		virtual void method() = 0;
	};

	class Object : public Interface
	{
	private:
		int data = 0;
	public:
		Object(int value);
		void method() override;
	};

	class ObjectProxy : public Interface
	{
	private:
		int valueA = 0;
		int valueB = 0;

		Object * obj;
	public:
		ObjectProxy(int value);
		~ObjectProxy();

		Object * operator->();

		void method() override;
	};
}