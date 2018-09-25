#include "TemplateExplicit.h"

template <typename T> TemplateExplicit<T>::TemplateExplicit()
{

}

template <typename T> TemplateExplicit<T>::TemplateExplicit(T value)
{
	data = value;
}

template <typename T> T TemplateExplicit<T>::getData() const
{
	return data;
}

template <typename T> void TemplateExplicit<T>::displayData() const
{
	cout << "Stored data: " << data << endl;
}

template class TemplateExplicit<int>;
template class TemplateExplicit<bool>;