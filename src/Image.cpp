#include "Image.h"
#include <iostream>


Image::Image(const Image& image)
    :Image(image.m_image.get_height(), image.m_image.get_width())
{
    for (int i = 0; i < m_image.get_height(); i++)
    {
        for (int j = 0; j < m_image.get_width(); j++)
        {
            m_image.set_pixel(i, j, image.m_image.get_pixel(i, j));
        }
    }
}
//===============================
Image::Image(const int height, const int width)
	:Image(height, width, ' ')
{}
//===============================
Image::Image(const int height, const int width, const Pixel pixel) 
	:m_image(height, width)
{
    m_image.set_height(height);
    m_image.set_width(width);
	fill_matrix(pixel);
}
//===============================
void Image::fill_matrix(Pixel pixel) {

    for (int i = 0; i < m_image.get_height(); ++i) {
        for (int j = 0; j < m_image.get_width(); ++j) {
            m_image(i, j) = pixel;
        }
    }
}
//===============================
Image& Image::operator=(const Image& other)
{
    Image temp(other);
    m_image.swap(temp.m_image);
    return *this;
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
//===============================
bool Image::operator!=(Image& other)
{
    if(*this == other)
    return false;
    return true;
}
//===============================
Image Image::operator+(const Image& other)
{
    Image temp(std::max(this->m_image.get_height(), other.m_image.get_height())
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
    }
   return temp;
}
//===============================
Image& Image::operator+=(const Image& other)
{
    *this = *this + other;
    return *this;
}
//============================
Image Image::operator|(const Image& other) 
{
    Image temp(std::max(m_image.get_height(), other.m_image.get_height()),
               std::max(m_image.get_width(), other.m_image.get_width()));

    for (int i = 0; i < temp.m_image.get_height(); ++i) 
    {
        for (int j = 0; j < temp.m_image.get_width(); ++j) 
        {
            Pixel pixel;

            if (i < m_image.get_height() && j < m_image.get_width() &&
                i < other.m_image.get_height() && j < other.m_image.get_width()) 
            {
                pixel = m_image.get_pixel(i, j) | other.m_image.get_pixel(i, j);
            }
            else if (i < m_image.get_height() && j < m_image.get_width()) 
            {
                pixel = m_image.get_pixel(i, j);
            }
            else if (i < other.m_image.get_height() && j < other.m_image.get_width()) 
            {
                pixel = other.m_image.get_pixel(i, j);
            }
            temp.m_image.set_pixel(i, j, pixel);
        }
    }
    return temp;
}
//===============================
Image& Image::operator|=(const Image& other)
{
    *this = *this | other;
    return *this;
}
//===============================
Image Image::operator&(const Image& other) 
{
    Image temp(std::min(m_image.get_height(), other.m_image.get_height()),
               std::min(m_image.get_width(), other.m_image.get_width()));

    for (int i = 0; i < temp.m_image.get_height(); ++i) 
    {
        for (int j = 0; j < temp.m_image.get_width(); ++j) 
        {
            Pixel pixel = m_image.get_pixel(i, j) & other.m_image.get_pixel(i, j);
            temp.m_image.set_pixel(i, j, pixel);
        }
    }
    return temp;
}
//============================
Image& Image::operator&=(const Image& other)
{
    *this = *this & other;
    return *this;
}
//=============================
Image Image::operator*(unsigned int n)const
{
    if (n <= 0)
        return Image(0, 0);

    Image temp(0, 0);
    for (int i = 0; i < n; i++)
        temp += *this;

    return temp;
}
//===============================
Image& Image::operator*=(unsigned int n)
{
    *this = *this * n;
    return *this;
}
//============================
Image Image::operator~()
{
    Image temp(m_image.get_height(), m_image.get_width());
    
    for (int i = 0; i < temp.m_image.get_height(); ++i)
    {
        for (int j = 0; j < temp.m_image.get_width(); ++j)
        {
            if(m_image.get_pixel(i,j) == (unsigned char)219)
                temp.m_image.set_pixel(i, j, ' ');

            else if (m_image.get_pixel(i, j) == ' ')
                temp.m_image.set_pixel(i, j, (unsigned char)219);
            else
            temp.m_image.set_pixel(i, j, (unsigned char)176);
        }
    }
    return temp;
}
//==========================================
Pixel& Image::operator()(const unsigned int i, const unsigned int j)
{
    return m_image.get_index(i, j);
}
//=============================
std::ostream& operator<<(std::ostream& os, const Image& other)
{
    for (int i = 0; i < other.m_image.get_height(); ++i)
    {
        for (int j = 0; j < other.m_image.get_width(); ++j)
        {
            std::cout << other.m_image.get_pixel(i, j);
        }
        std::cout << '\n';
    }
    return os << '\n';
}

Image operator*(unsigned int n, const Image& other)
{
    return other * n ;
}
