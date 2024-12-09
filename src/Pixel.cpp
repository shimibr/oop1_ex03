#include "Pixel.h"
#include <iostream>


Pixel::Pixel(unsigned char pixel)
	:m_pixel(pixel)
{
}

bool Pixel::operator==(const Pixel& other) const
{
	return m_pixel == other.m_pixel;
}

bool Pixel::operator!=(const Pixel& other) const
{
	return m_pixel != other.m_pixel;
}

Pixel Pixel::operator|(const Pixel& other) const
{
	if(m_pixel > other.m_pixel)
		return *this;
	return other;
}

Pixel Pixel::operator|=(const Pixel& other) 
{
	*this = *this | other;
	return *this;
}

Pixel Pixel::operator&(const Pixel& other) const
{
	if (this->m_pixel < other.m_pixel)
		return *this;
	return other;
}

Pixel Pixel::operator&=(const Pixel& other) 
{
	*this = *this & other;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Pixel& other) 
{
	return os<<other.m_pixel;
}
