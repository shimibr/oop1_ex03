#include "ImageDataStructure.h"
#include <charconv>
#include <iostream>

ImageDataStructure::ImageDataStructure(const int height, const int width)
	:m_height(height),m_width(width)
{ 
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
Pixel ImageDataStructure::get_pixel(const int row, const int col) const
{
	return m_image[row][col];
}
//===========================
void ImageDataStructure::set_pixel(const int row, const int col, Pixel pixel)
{
	m_image[row][col] = pixel;
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
//===========================
void ImageDataStructure::set_height(const int height)
{
	m_height = height;
}
//===========================
void ImageDataStructure::set_width(const int width)
{
	m_width = width;
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
