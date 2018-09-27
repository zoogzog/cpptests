#include "CPP11Utils.h"


int bind_add(int op1, int op2) { return op1 + op2; }
bool bind_isstringequal(string op1, string op2) { if (op1 == op2) { return true; } return false; }

int bind_findstring(string query)
{
	string data[] = { "abc", "ccc", "ddd", "eee", "bvx", "opx", "xxx", "bxx", "xxx", "ccb" };

	return std::count_if(data, data + 10, std::bind(&bind_isstringequal, _1, query));
}

string auto_function001()
{
	return "function001";
}


int vtemplatesum()
{
	return 0;
}