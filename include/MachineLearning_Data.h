/********************************************************************************
Copyright (c) 2013-2014 Hironori Hattori <hattorih@cs.cmu.edu>.
All rights reserved.
---------------------------------------------------------------------------------
$Id: $
********************************************************************************/

// "libMachineLearning - Data"

// Hironori Hattori, Carnegie Mellon University
// hattorih@cs.cmu.edu


#ifndef __LIB_MACHINE_LEARNING_DATA_H__
#define __LIB_MACHINE_LEARNING_DATA_H__


#include "MachineLearning_Element.h"


namespace MachineLearning
{


template <class T>
class Data : public std::vector<Element<T>>
{
public:
	Data (T class_ = 0, T score_ = 0, std::string tag_ = "n/a");

	~Data (void);

	const T &getClass (void) const { return mClass; }
	T &getClass (void) { return mClass; }

	const T &getScore (void) const { return mScore; }
	T &getScore (void) { return mScore; }

	const std::string &getTag (void) const { return mTag; }
	std::string &getTag (void) { return mTag; }

	int getMinIndexOfElement (void) const;
	int getMaxIndexOfElement (void) const;

	T getMinValueOfElement (void) const;
	T getMaxValueOfElement (void) const;

private:
	T mClass;
	T mScore;

	std::string mTag;
};

typedef Data<float> Data_f32;
typedef Data<double> Data_f64;


} // namespace MachineLearning


#endif // __LIB_MACHINE_LEARNING_DATA_H__

