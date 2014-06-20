/********************************************************************************
Copyright (c) 2013-2014 Hironori Hattori <hattorih@cs.cmu.edu>.
All rights reserved.
---------------------------------------------------------------------------------
$Id: $
********************************************************************************/

// "libMachineLearning - Dataset"

// Hironori Hattori, Carnegie Mellon University
// hattorih@cs.cmu.edu


#ifndef __LIB_MACHINE_LEARNING_DATASET_H__
#define __LIB_MACHINE_LEARNING_DATASET_H__


#include "MachineLearning_Data.h"

#if defined (__USE_OPENCV__)
#include "opencv2/imgproc/imgproc.hpp"
#endif


namespace MachineLearning
{


template <class T>
class Dataset : public std::vector<Data<T>>
{
public:
	Dataset (void);

	~Dataset (void);
 
	int getMinIndexOfElement (void) const;
	int getMaxIndexOfElement (void) const;

	T getMinValueOfElement (void) const;
	T getMaxValueOfElement (void) const;

	bool read (const std::string &filename);
	bool write (const std::string &filename);

#if defined (__USE_OPENCV__)
	CvMat *createElementMat() const;
	CvMat *createClassMat() const;
#endif
};

typedef Dataset<float> Dataset_f32;
typedef Dataset<double> Dataset_f64;


} // namespace MachineLearning


#endif // __LIB_MACHINE_LEARNING_DATASET_H__

