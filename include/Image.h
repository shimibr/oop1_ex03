#pragma once
#include "Pixel.h"
#include "ImageDataStructure.h"

class Image
{
public:
	Image(const int height, const int width);
	Image(const int height, const int width, const Pixel pixel);
	void fill_matrix(Pixel pixel);
	friend void operator<<(std::ostream& os, const Image& other);


	bool operator==(Image& other);
	bool operator!=(Image& other);
	Image operator+(Image& other);

	//~Image();

private:
	ImageDataStructure m_image;

};
