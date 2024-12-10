#include "Pixel.h"
#include "Image.h"
#include <iostream>

int main()
{
	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	
	Image matrix1(2, 2, GRAY);
	Image matrix2(2, 2, GRAY);
	if(matrix1 == matrix2)
	//matrix.print_matrix();

	return 0;
}