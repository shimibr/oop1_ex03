#pragma once
#include "Pixel.h"
#include "ImageDataStructure.h"

class Image
{
public:
	//Image();
	Image(const int height, const int width);
	Image(const int height, const int width, const Pixel pixel);
	void fill_matrix(Pixel pixel);
	void print_matrix();

	bool operator==(Image& other);

	//~Image();

private:
	ImageDataStructure m_image;
	int m_height, m_width;

};
