#pragma once
#include "Pixel.h"
#include "ImageDataStructure.h"

class Image
{
public:
	Image(const Image& image);
	Image(const int height, const int width);
	Image(const int height, const int width, const Pixel pixel);
	void fill_matrix(Pixel pixel);
	friend std::ostream& operator<<(std::ostream&, const Image&);
	Image& operator=(const Image& other);
	bool operator==(Image& other);
	bool operator!=(Image& other);
	Image operator+(const Image& other);
	Image& operator+=(const Image& other);
	Image operator|(const Image& other);
	Image& operator|=(const Image& other);
	Image operator&(const Image& other);
	Image& operator&=(const Image& other);
	Image operator*(unsigned int n) const;
	Image& operator*=(unsigned int n);
	Image operator~();
	friend Image operator*(unsigned int n, const Image& other);
	Pixel& operator()(const unsigned int i, const unsigned int j);

	//~Image();

private:
	ImageDataStructure m_image;

};