#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>
using namespace std;

namespace examplethread
{
	class ThreadFunction
	{
	public:
		void operator()()
		{
			for (int i = 0; i < 10; i++)
			{
				cout << "Running a thread" << endl;

				
			}
		}
	};

	void threadpromise(promise<int> * probj);

	class ThreadRunner
	{
	public:
		static void run();
		static void runfuture();
	};
}