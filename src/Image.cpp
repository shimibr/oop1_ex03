#include "Image.h"
#include <iostream>


Image::Image(const ImageDataStructure& image)
    :m_image(image)
{
}

Image::Image(const int height, const int width)
	:Image(height, width, ' ')
{}

Image::Image(const int height, const int width, const Pixel pixel) 
	:m_image(height, width)
{
    m_image.set_height(height);
    m_image.set_width(width);
	fill_matrix(pixel);
}

void Image::fill_matrix(Pixel pixel) {

    for (int i = 0; i < m_image.get_height(); ++i) {
        for (int j = 0; j < m_image.get_width(); ++j) {
            m_image(i, j) = pixel;
        }
    }
}
//============================
bool Image::operator==(Image& other)
{
    if (this->m_image.get_height() != other.m_image.get_height() ||
        this->m_image.get_width() != other.m_image.get_width())
        return false;


    for (int i = 0; i < m_image.get_height(); ++i)
    {
        for (int j = 0; j < m_image.get_width(); ++j)
        {
            if (this->m_image.get_pixel(i,j) != other.m_image.get_pixel(i,j))
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

Image Image::operator+(Image& other)
{
 /*   Image temp(std::max(this->m_image.get_height(), other.m_image.get_height())
               ,this->m_image.get_width() + other.m_image.get_width());

    for (int i = 0; i < temp.m_image.get_height(); i++)
    {
        for (int  j = 0; j < temp.m_image.get_width(); j++)
        {
            if ((i >= this->m_image.get_height() && j < this->m_image.get_width()) ||
                (i >= other.m_image.get_height() && (j >= this->m_image.get_width() )))
                j++;
               
            else if (j < this->m_image.get_width())
                temp.m_image.set_pixel(i, j, this->m_image.get_pixel(i, j));
            else if ((j - this->m_image.get_width()) < other.m_image.get_width())
                temp.m_image.set_pixel(i, j, other.m_image.get_pixel(i, j - this->m_image.get_width()));

        }
    }*/
    Image temp((this->m_image + other.m_image));
    //temp.m_image = (this->m_image + other.m_image);
    
    
    return temp;
}

void operator<<(std::ostream& os, const Image& other)
{
   /* for (int i = 0; i < other.m_image.get_height(); ++i)
    {
        for (int j = 0; j < other.m_image.get_width(); ++j)
        {
            std::cout << other.m_image.get_pixel(i,j);
        }
        std::cout << '\n';
    }*/
    std::cout << other.m_image;
}
