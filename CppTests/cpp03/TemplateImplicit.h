#pragma once

#include <iostream>

using namespace std;

template <typename TemplateVar> class TemplateImplicit
{
private:
	TemplateVar data;

public:
	TemplateImplicit();
	TemplateImplicit(TemplateVar v);

	//---- Since these functions do not change data, prohibit it from changing with 'const' key word
	TemplateVar getData() const;
	void displayData() const;
};

//---- Implicit instantiation of the template

template <typename TemplateVar> TemplateImplicit<TemplateVar>::TemplateImplicit()
{

}

template <typename TemplateVar> TemplateImplicit<TemplateVar>::TemplateImplicit(TemplateVar v)
{
	data = v;
}

template <typename TemplateVar> TemplateVar TemplateImplicit<TemplateVar>::getData() const
{
	return data;
}

template <typename TemplateVar> void TemplateImplicit<TemplateVar>::displayData() const
{
	cout << "Stored data: " << data << endl;
}