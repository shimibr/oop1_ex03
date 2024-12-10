#include "Pixel.h"
#include "Image.h"
#include <iostream>

int main()
{
	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	
	Image matrix1(2, 4, BLACK);
	Image matrix2(2, 2, GRAY);
	
	//std::cout << matrix2 << '\n';
	std::cout << (matrix1 + matrix2);
	return 0;
}