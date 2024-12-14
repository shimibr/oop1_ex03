#include "ImageDataStructure.h"
#include <charconv>
#include <iostream>

ImageDataStructure::ImageDataStructure(const int height, const int width)
	:m_height(height),m_width(width),m_image(nullptr)
{ 
	if(m_height > 0 && m_width > 0)
		m_image = bild_matrix();
}
//==========================
ImageDataStructure::~ImageDataStructure()
{
	for (int i = 0; i < m_height; ++i)
        delete[] m_image[i];
    
    delete[] m_image;
}
//===========================
Pixel& ImageDataStructure::operator()(int row, int col) const 
{
	return m_image[row][col];
}
//===========================
int ImageDataStructure::get_height() const
{
	return m_height;
}
//===========================
int ImageDataStructure::get_width() const
{
	return m_width;
}
//====================
void ImageDataStructure::swap(ImageDataStructure& other)
{
	std::swap(m_image, other.m_image);
	std::swap(m_height, other.m_height);
	std::swap(m_width, other.m_width);
		
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
