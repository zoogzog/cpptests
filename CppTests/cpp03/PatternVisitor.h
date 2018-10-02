#pragma once

#include <iostream>

using namespace std;

namespace examplevisitor
{
	class ObjectInterface
	{
	public:
		virtual void accept(class VisitorInterface * v) = 0;
	};

	class ObjectA : public ObjectInterface
	{
	public:
		/*virtual*/void accept(VisitorInterface * v);
		void randommethodA();
	};

	class ObjectB : public ObjectInterface
	{
	public:
		/*virtual*/void accept(VisitorInterface * v);
		void randommehtodB();
	};

	//--------------------------------------------------------

	class VisitorInterface
	{
	public:
		virtual void visit(ObjectA * obj) = 0;
		virtual void visit(ObjectB * obj) = 0;
	};

	class VisitorA : public VisitorInterface
	{
	public:
		void visit(ObjectA * obj);
		void visit(ObjectB * obj);
	};

	class VisitorB : public VisitorInterface
	{
	public:
		void visit(ObjectA * obj);
		void visit(ObjectB * obj);
	};


}