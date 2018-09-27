#include "PatternObjectPool.h"


Resource::Resource()
{
	data = 0;
}

int Resource::valueGet()
{
	return data;
}

void Resource::valueSet(int value)
{
	data = value;
}

void Resource::reset()
{
	data = 0;
}

PatternObjectPool * PatternObjectPool::getInstance()
{
	if (!instance)
	{
		instance = new PatternObjectPool();
	}

	return instance;
}

PatternObjectPool::PatternObjectPool()
{
	resourceused = 0;
}

Resource * PatternObjectPool::resourceGet()
{
	if (resourceused == this->POOL_MAX) 
	{ 
		cout << "Can't provide resource" << endl;
		return 0; 
	}


	if (resourcepool.empty())
	{
		cout << "New resource is created" << endl;
		resourceused++;
		return new Resource;
	}
	else
	{
		cout << "Providing existing resource" << endl;

		Resource * resource = resourcepool.front();
		resourcepool.pop_front();
		resourceused++;
		return resource;
	}
}

void PatternObjectPool::resourceReturn(Resource * object)
{
	if (resourcepool.size() < POOL_MAX)
	{
		object->reset();
		resourcepool.push_back(object);

		resourceused--;

		cout << "Resource is returned" << endl;
	}
}

PatternObjectPool * PatternObjectPool::instance = 0;
