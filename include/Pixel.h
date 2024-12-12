#pragma once
#include <iosfwd>

class Pixel
{
public:
	Pixel(const unsigned char pixel = ' ');

	bool operator==(const Pixel& other) const;
	bool operator!=(const Pixel& other) const;
	Pixel operator|(const Pixel& other) const;
	Pixel operator|=(const Pixel& other);
	Pixel operator&(const Pixel& other) const;
	Pixel operator&=(const Pixel& other);

	
	
	friend std::ostream& operator<<(std::ostream& os, const Pixel& other);

private:
	unsigned char m_pixel;

};
