#include "CPP11Smrtptr.h"

using namespace smrtptr;

void ptrdelete(StructureA * x)
{
	delete[] x;
}

void Test001::run()
{
	//---- Shared ptr for an int
	//---- Compile error:	shared_ptr<int> ptr1 = new int();
	//---- Good way:		shared_ptr<int> ptr1 = make_shared<int>();
	shared_ptr<int> ptr1(new int());

	//---- Shared ptr for a structure
	shared_ptr<StructureA> ptr2(new StructureA());

	//---- Using the * operator or ->
	*ptr1 = 66;
	
	ptr2->x = 66;
	ptr2->y = 77;
	ptr2->z = 88;

	cout << "PTR1: " << *ptr1 << endl;
	cout << "PTR COUNT: " << ptr1.use_count() << endl;

	//---- Initialization with another pointer
	shared_ptr<StructureA> ptr3 = ptr2;

	cout << "PTR SAME MEMORY: " << ptr3->x << " " << ptr3->y << " " << ptr3->z << endl;

	shared_ptr<int> ptr4;

	cout << "PTR4 global scope: " << ptr4.use_count() << endl;
	//---- Testing the local scope deletion
	{
		ptr4 = make_shared<int>();
		cout << "PTR4 local scope: " << ptr4.use_count() << endl;

		ptr1 = ptr4;
		ptr4 = nullptr;
	}
	cout << "PTR4 global scope after: " << ptr4.use_count() << endl;
	cout << "PTR1 global scope after: " << ptr1.use_count() << endl;

	//---- Array
	shared_ptr<int[]> ptrarray(new int[3]);
	ptrarray[0] = 4;
	cout << "Array element: " << ptrarray[0] << endl;

	cout << "GET INTO LOCAL SCOPE" << endl;
	{
		//---- Array of custom objects with a custom deleter
		shared_ptr<StructureA> ptrarr(new StructureA[3], ptrdelete);
		
		cout << "Creating basic array" << endl;

		StructureA * bb = new StructureA[4];
	}
	cout << "LEAVE THE LOCAL SCOPE" << endl;


	//----------- !!! DANGLING POINTER EXAMPLE
	//StructureA * rawptr = new StructureA();
	//shared_ptr<StructureA> dgptr1(rawptr);
	//{shared_ptr<StructureA> dgptr2(rawptr); } 
}

void Test002::run()
{
	shared_ptr<int> ptr1 = make_shared<int>(4);
	weak_ptr<int> weakptr(ptr1);
	shared_ptr<int> ptr2 = weakptr.lock();

	if (ptr2) { cout << *ptr2 << endl; }

	cout << "PTR count " << ptr2.use_count() << endl;

	if (weakptr.expired() == false) { cout << "Weak ptr is not expired" << endl; }
}