#include "Pixel.h"


class ImageDataStructure
{
public:
	ImageDataStructure(const int H,const int W);

	~ImageDataStructure();

private:
	Pixel** bild_matrix();

	Pixel** m_image;
	int m_h, m_w;
};


