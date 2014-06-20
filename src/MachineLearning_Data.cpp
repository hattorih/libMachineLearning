#include "MachineLearning_Data.h"

#include <limits.h>
#include <float.h>
#include <assert.h>


namespace MachineLearning
{


template <class T>
Data<T>::Data (T class_, T score_, std::string tag_) :
mClass(class_), mScore(score_), mTag(tag_)
{
	;
}


template <class T>
Data<T>::~Data (void)
{
	;
}


template <class T>
int Data<T>::getMinIndexOfElement (void) const
{
	assert(size() != 0);

	int idx = INT_MAX;
	for (unsigned int i=0; i<this->size(); i++)
		if (this->at(i).getIndex() < idx) idx = this->at(i).getIndex();

	return idx;
}


template <class T>
int Data<T>::getMaxIndexOfElement (void) const
{
	assert(size() != 0);

	int idx = INT_MIN;
	for (unsigned int i=0; i<this->size(); i++)
		if (idx < this->at(i).getIndex()) idx = this->at(i).getIndex();

	return idx;
}


template <class T>
T Data<T>::getMinValueOfElement (void) const
{
	assert(size() != 0);

	T val = FLT_MAX;
	for (unsigned int i=0; i<this->size(); i++)
		if (this->at(i).getValue() < val) val = this->at(i).getValue();

	return val;
}


template <class T>
T Data<T>::getMaxValueOfElement (void) const
{
	assert(size() != 0);

	T val = FLT_MIN;
	for (unsigned int i=0; i<this->size(); i++)
		if (val < this->at(i).getValue()) val = this->at(i).getValue();

	return val;
}


// Explicit Instantiation
template class Data<float>;
template class Data<double>;


} // namespace MachineLearning

