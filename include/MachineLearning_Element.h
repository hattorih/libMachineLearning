/********************************************************************************
Copyright (c) 2013-2014 Hironori Hattori <hattorih@cs.cmu.edu>.
All rights reserved.
---------------------------------------------------------------------------------
$Id: $
********************************************************************************/

// "libMachineLearning - Element"

// Hironori Hattori, Carnegie Mellon University
// hattorih@cs.cmu.edu


#ifndef __LIB_MACHINE_LEARNING_ELEMENT_H__
#define __LIB_MACHINE_LEARNING_ELEMENT_H__


#include <vector>


namespace MachineLearning
{


template <class T>
class Element
{
public:
	Element (int index_ = 0, T value_ = 0);

	~Element (void);

	const int &getIndex (void) const { return mIndex; }
	int &getIndex (void) { return mIndex; }

	const T &getValue (void) const { return mValue; }
	T &getValue (void) { return mValue; }

private:
	int mIndex;

	T mValue;
};

typedef Element<float> Element_f32;
typedef Element<double> Element_f64;


} // namespace MachineLearning


#endif // __LIB_MACHINE_LEARNING_ELEMENT_H__

