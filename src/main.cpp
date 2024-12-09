#include "Pixel.h"
#include <iostream>

int main()
{
	const unsigned char BLACK = (unsigned char)219;
	const unsigned char GRAY = (unsigned char)176;
	Pixel p1;
	Pixel p2(GRAY);
	Pixel p3(BLACK);


	std::cout << p1 << p2 << p3;
	p1 = p3;
	if(p1==p3)
	std::cout << (p2 & p3) <<p1 << p3;
	

	return 0;
}