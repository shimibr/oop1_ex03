#include "ImageDataStructure.h"

ImageDataStructure::ImageDataStructure(const int height, const int width)
	:m_height(height),m_width(width) { 
	m_image = bild_matrix();
}
//==========================
ImageDataStructure::~ImageDataStructure()
{
	for (int i = 0; i < m_height; ++i)
        delete[] m_image[i];
    
    delete[] m_image;
}
Pixel& ImageDataStructure::operator()(int row, int col) const 
{
	return m_image[row][col];
}
//=========================
Pixel** ImageDataStructure::bild_matrix()
{
	Pixel** temp = new Pixel* [m_height];

	for (int i = 0; i < m_height; ++i)
		temp[i] = new Pixel[m_width];
	
	return temp;
}
//=============================
Pixel& ImageDataStructure::operator[](int row, int col) {
	
	return m_image[row][col];
}

