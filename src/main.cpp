#include "Pixel.h"
#include "Image.h"
#include "ImageDataStructure.h"
#include <iostream>

int main()
{
	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	
	Image matrix1(7, 7, BLACK);
	Image matrix2(4, 8, GRAY);
	std::cout << (matrix1);
	std::cout << (matrix2);
	matrix1 = 5 * matrix1;
	matrix1(1, 1) = GRAY;
	std::cout << (~matrix1) << '\n';
	std::cout << (matrix1);

	return 0;
}