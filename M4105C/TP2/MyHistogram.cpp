#include "MyHistogram.hpp"


MyHistogram::MyHistogram(MyImage& image)
{
	MyImage temp(image);
	for(int i=0; i<256; i++) {
		m_histogram[i] = 0;
	}
	
	temp.Desaturate();
	
	unsigned char* data = temp.GetData();
	int size = temp.GetWidth() + temp.GetHeight() * 3;
	for(int i=0 ;i<size; i+=3) {
		m_histogram[int(data[i])]++;
	}
}

MyHistogram::~MyHistogram()
{
}

void MyHistogram::GetDynamic(int* minValue, int* maxValue) {
	*maxValue = 255;
	*minValue = 0;
	while(m_histogram[*minValue] == 0 && *minValue < 255) {
		*minValue += 1;
	}
	
	while(m_histogram[*maxValue] == 0 && *maxValue > 0) {
		*maxValue -= 1;
	}
	
	std::cout << "min : " << *minValue << " max : " << *maxValue << std::endl;
}

