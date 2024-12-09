#include "ImageDataStructure.h"


ImageDataStructure::ImageDataStructure(const int H, const int W)
	:m_h(H),m_w(W),m_image(bild_matrix()) { }

ImageDataStructure::~ImageDataStructure()
{
	for (int i = 0; i < m_h; ++i) 
        delete[] m_image[i];
    
    delete[] m_image;
}

Pixel** ImageDataStructure::bild_matrix()
{
	Pixel** temp = new Pixel * [m_h];

	for (int i = 0; i < m_h; ++i) 
		temp[i] = new Pixel[m_w];
	
	return temp;
}
