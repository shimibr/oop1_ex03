#pragma once
#include "Pixel.h"


class ImageDataStructure
{
public:
	ImageDataStructure(const int height,const int width);
	~ImageDataStructure();
	Pixel& operator()(int row, int col) const;
	Pixel get_pixel(const int row, const int col) const;
	void set_pixel(const int row, const int col, Pixel pixel);
	int get_height() const;
	int get_width() const;
	void set_height(const int height);
	void set_width(const int width);
	ImageDataStructure operator+(ImageDataStructure& other);
	ImageDataStructure& operator=(const ImageDataStructure& other);
	friend void operator<<(std::ostream& os, const ImageDataStructure& other);

private:
	Pixel** bild_matrix() ;

	Pixel** m_image;
	int m_height = 0, m_width = 0;
};


