#include "CPP11Thread.h"


using namespace examplethread;

void ThreadRunner::run()
{
	//---- In case of sending the class put it in the brackets
	std::thread mythread((ThreadFunction()));
	cout << "Waiting for thread" << endl;

	//---- Blocking wait
	mythread.join();

	cout << "All threads have joined main thread" << endl;

	mythread = thread((ThreadFunction()));

	//---- Continue execution of the main thread
	

	cout << "Detached" << endl;

	mythread.join();
}

void examplethread::threadpromise(promise<int> * probj)
{
	cout << "Setting promise";
	this_thread::sleep_for(4s);
	probj->set_value(45);
}

void ThreadRunner::runfuture()
{
	promise<int> probj;
	future<int> fuobj = probj.get_future();

	thread th(threadpromise, &probj);

	cout << "Blocking until get the promise is set" << endl;
	fuobj.get();

	cout << "Future is set" << endl;
	th.join();


}