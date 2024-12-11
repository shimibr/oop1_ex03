#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"
#include <iostream>

int main()
{
	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	
	Image matrix1(2, 2, BLACK);
	Image matrix2(2, 2, GRAY);
	matrix2 = (matrix2 + matrix1);
	std::cout << matrix2;

	return 0;
}