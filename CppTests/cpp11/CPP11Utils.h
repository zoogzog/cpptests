#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class ClassInitializerList
{
private:
	vector<int> v;
	int x[4];
public:
	ClassInitializerList(std::initializer_list<int> l) { v = l; }
	ClassInitializerList() : x{ 0, 1, 2, 3 } {};
	void print() 
	{
		string out = "";
		for (int k = 0; k < v.size(); k++)
		{
			out.append(std::to_string(v.at(k)));
			out.append(" ");
		}

		cout << out << endl;

		for (int p = 0; p < 4; p++)
		{
			cout << x[p] << " ";
		}
		cout << endl;
	}
};