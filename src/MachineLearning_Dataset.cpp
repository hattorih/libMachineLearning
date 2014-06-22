#include "MachineLearning_Dataset.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <float.h>
#include <assert.h>


namespace MachineLearning
{


template <class T>
Dataset<T>::Dataset (void)
{
	;
}


template <class T>
Dataset<T>::~Dataset (void)
{
	;
}


template <class T>
int Dataset<T>::getMinIndexOfElement (void) const
{
	assert(size() != 0);

	int idx = INT_MAX;
	for (unsigned int i=0; i<size(); i++)
	{
		int temp = this->at(i).getMinIndexOfElement();
		if (temp < idx) idx = temp;
	}

	return idx;
}


template <class T>
int Dataset<T>::getMaxIndexOfElement (void) const
{
	assert(size() != 0);

	int idx = INT_MIN;
	for (unsigned int i=0; i<size(); i++)
	{
		int temp = this->at(i).getMaxIndexOfElement();
		if (idx < temp) idx = temp;
	}

	return idx;
}


template <class T>
T Dataset<T>::getMinValueOfElement (void) const
{
	assert(size() != 0);

	T value = FLT_MAX;
	for (unsigned int i=0; i<size(); i++)
	{
		T temp = this->at(i).getMinValueOfElement();
		if (temp < value) value = temp;
	}

	return value;
}


template <class T>
T Dataset<T>::getMaxValueOfElement (void) const
{
	assert(size() != 0);

	T value = FLT_MIN;
	for (unsigned int i=0; i<size(); i++)
	{
		T temp = this->at(i).getMaxValueOfElement();
		if (value < temp) value = temp;
	}

	return value;
}


template <class T>
bool Dataset<T>::read (const std::string &filename)
{
	std::ifstream in(filename.c_str());
	std::cout << "Read dataset(" << filename << ")" << std::endl;

	if (!in)
	{
		std::cout << "---> ERROR!" << std::endl;
		return false;
	}
	else
	{
		Dataset<T> temp;

		while (!in.eof())
		{
			Data<T> d;

			std::string line;
			std::getline(in, line);

			while (line.length() != 0 && line[0] == '#')
			{
				d.getTag() = line.substr(1);
				std::getline(in, line);
			}

			if (line.length() != 0 && line[0] != '#')
			{
				std::istringstream in_line(line);
				in_line >> d.getClass();

				char c;
				Element<T> e;
				while (in_line >> e.getIndex() >> c >> e.getValue())
					if (c == ':') d.push_back(e);

				temp.push_back(d);
			}

			if (temp.size() % 100 == 0)
				printf ("---> (%08d)\r", temp.size());
		}
		in.close();

		unsigned int max_index = temp.getMaxIndexOfElement();

		resize(temp.size());

		for (unsigned int i=0; i<temp.size(); i++)
		{
			Data<T> &d = this->at(i);

			d.getTag() = temp[i].getTag();
			d.getClass() = temp[i].getClass();

			if (d.size() < max_index) d.resize(max_index);
			for (unsigned int j=0; j<max_index; j++) d[j].getIndex() = j;

			/* The svmlight's index starts from 1.            */
			/* But this dataset's index starts from 0.        */
			/* Then, in this process index = index_input - 1. */
			for (unsigned int j=0; j<temp[i].size(); j++)
			{
				int index = temp[i][j].getIndex() - 1;
				T value = temp[i][j].getValue();
				//printf ("%5d %f\n", index, value);

				d[index].getValue() = value;
			}
			printf ("---> Adjust(%05d)\r", i);
		}

		printf ("---> Complete! (%05d)\n", size());

		return true;
	}
}


template <class T>
bool Dataset<T>::write (const std::string &filename)
{
	std::ofstream out(filename.c_str());
	std::cout << "Write dataset(" << filename << ")" << std::endl;

	if (!out)
	{
		std::cout << "---> ERROR!" << std::endl;
		return false;
	}
	else
	{
		out << "#" << size() << std::endl;
		for (unsigned int i=0; i<size(); i++)
		{
			Data<T> &d = this->at(i);

			out << "#" << i << std::endl;
			out << "#" << d.getTag() << std::endl;
			out << ((d.getClass() == 0) ? "0" : ((d.getClass() < 0) ? "-1" : "+1"));

			/* The svmlight's index starts from 1.             */
			/* But this dataset's index starts from 0.         */
			/* Then, in this process index_output = index + 1. */
			for (unsigned int n=0; n<d.size(); n++)
				if (d[n].getValue() != 0)
					out << " " << d[n].getIndex() + 1 << ":" << d[n].getValue();

			out << std::endl;

			printf ("---> (%05d/%05d)\r", i, size());
		}
		out.close();
		printf ("---> Complete! (%05d)\n", size());
		return true;
	}
}


#if defined (__USE_OPENCV__)
template <class T>
CvMat *Dataset<T>::createElementMat() const
{
	int max_index = getElementIndexMax() + 1;

	CvMat *data = cvCreateMat( size(), max_index, CV_32F );
	cvSet( data, cvRealScalar(0) );
	for (unsigned int i=0; i<size(); i++)
	{
		const Data<T> &d = (*this)[i];
		float *ptr = data->data.fl + max_index * i;
		for (unsigned int j=0; j<(unsigned int)max_index; j++)
			ptr[d[j].getIndex()] = (float)(d[j].getValue());
	}

	return data;
}
#endif


#if defined (__USE_OPENCV__)
template <class T>
CvMat *Dataset<T>::createClassMat() const
{
	CvMat *responses = cvCreateMat( size(), 1, CV_32F );
	for (unsigned int i=0; i<size(); i++)
		responses->data.fl[i] = (float)((*this)[i].getClass());

	return responses;
}
#endif


// Explicit Instantiation
template class Dataset<float>;
template class Dataset<double>;


} // namespace MachineLearning

