#include "MachineLearning_Include.h"

#include <iostream>


#define FILENAME "..\\..\\data\\dataset.txt"


int main (int argc, char **argv)
{
	{
		MachineLearning::Dataset_f32 dataset;
		dataset.read(FILENAME);
	}

	{
		MachineLearning::Data_f32 data1(0, 0, "data1");
		data1.push_back(MachineLearning::Element_f32 (1, 10));
		data1.push_back(MachineLearning::Element_f32 (3, 15));
		data1.push_back(MachineLearning::Element_f32 (2, 20));

		MachineLearning::Data_f32 data2(0, 0, "data2");
		data2.push_back(MachineLearning::Element_f32 (2, 20));
		data2.push_back(MachineLearning::Element_f32 (6, 30));
		data2.push_back(MachineLearning::Element_f32 (4, 40));

		MachineLearning::Dataset_f32 dataset;
		dataset.push_back(data1);
		dataset.push_back(data2);

		std::cout << dataset.getMaxIndexOfElement() << std::endl;
		std::cout << dataset.getMinIndexOfElement() << std::endl;

		std::cout << dataset.getMaxValueOfElement() << std::endl;
		std::cout << dataset.getMinValueOfElement() << std::endl;

		dataset.write(FILENAME);
	}

	return 0;
}

