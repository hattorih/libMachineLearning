#include "MachineLearning_Element.h"


namespace MachineLearning
{


template <class T>
Element<T>::Element (int index_, T value_) :
mIndex(index_), mValue(value_)
{
	;
}


template <class T>
Element<T>::~Element (void)
{
	;
}


// Explicit Instantiation
template class Element<float>;
template class Element<double>;


} // namespace MachineLearning

