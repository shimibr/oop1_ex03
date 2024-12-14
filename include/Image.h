#pragma once
#include "Pixel.h"
#include "ImageDataStructure.h"

class Image
{
public:
	Image();
	Image(const Image& image);
	Image(const int height, const int width);
	Image(const int height, const int width, const Pixel pixel);

	friend std::ostream& operator<<(std::ostream&, const Image&);
	Image& operator=(const Image& other);
	bool operator==(const Image& other) const;
	bool operator!=(const Image& other) const;
	Image operator+(const Image& other) const;
	Image& operator+=(const Image& other);
	Image operator|(const Image& other) const;
	Image& operator|=(const Image& other);
	Image operator&(const Image& other) const;
	Image& operator&=(const Image& other);
	Image operator*(const unsigned int n) const;
	Image& operator*=(const unsigned int n);
	friend Image operator*(const unsigned int n, const Image& other);
	friend Image operator*=(const unsigned int n, Image& other);
	Image operator~();
	Pixel& operator()(const unsigned int i, const unsigned int j);
	const Pixel& operator()(const unsigned int i, const unsigned int j) const;

	int GetHeight() const;
	int GetWidth() const;

private:
	void fill_matrix(Pixel pixel);

	ImageDataStructure m_image;

};