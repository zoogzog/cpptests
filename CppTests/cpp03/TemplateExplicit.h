#pragma once

#include <iostream>

using namespace std;

template <typename T> class TemplateExplicit
{
private:
	T data;
public:
	TemplateExplicit();
	TemplateExplicit(T value);

	T getData() const;
	void displayData() const;
};

