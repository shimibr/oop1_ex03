#include "Image.h"
#include <iostream>


//Image::Image() :m_height(0), m_width(0) { }

Image::Image(const int height, const int width)
	:m_image(height, width), m_height(height), m_width(width) { }

Image::Image(const int height, const int width, const Pixel pixel) 
	:m_image(height, width), m_height(height), m_width(width)
{
	fill_matrix(pixel);
}

void Image::fill_matrix(Pixel pixel) {

    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            m_image(i, j) = pixel;
        }
    }
}

void Image::print_matrix()
{
    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j) {
            std::cout << m_image(i, j);
        }
    }
}
bool Image::operator==(Image& other)
{
    if (this->m_height != other.m_height ||
        this->m_width != other.m_width)
        return false;


    for (int i = 0; i < m_height; ++i)
    {
        for (int j = 0; j < m_width; ++j)
        {
            if (this->m_image(i, j) != other.m_image(i, j))
            {
                return false;
            }
        }
    }

    return true;
}
bool Image::operator!=(Image& other)
{
    if(*this == other)
    return false;
    return true;
}


