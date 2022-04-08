#ifndef MYHISTOGRAM_HPP
#define MYHISTOGRAM_HPP

#include "MyImage.hpp"

class MyHistogram
{
public:
	
	MyHistogram(MyImage& image);
	~MyHistogram();
	
	void GetDynamic(int* minValue, int* maxValue);
	bool CanBeFucked();
	
private:

	unsigned int m_histogram[256];
};

#endif // MYHISTOGRAM_HPP
