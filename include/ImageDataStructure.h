#pragma once
#include "Pixel.h"


class ImageDataStructure
{
public:
	ImageDataStructure(const int height,const int width);
	~ImageDataStructure();

	Pixel& operator()(int row, int col) const;
	void swap(ImageDataStructure& other);
	int get_width() const;
	int get_height() const;
private:
	Pixel** bild_matrix() ;

	Pixel** m_image;
	int m_height = 0, m_width = 0;
};


