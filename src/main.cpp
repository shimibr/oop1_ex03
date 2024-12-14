#include <iostream>
#include "Pixel.h"
#include "ImageDataStructure.h"
#include "Image.h"

#include <ostream>

using namespace std;


int main()
{
    const unsigned char BLACK = (unsigned char)219;
    const unsigned char GRAY = (unsigned char)176;
    const unsigned char WHITE = ' ';
    // ====== Pixel ������ ����� ==============
    Pixel p1(BLACK);
    Pixel p2(GRAY);
    Pixel p3(WHITE);


    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;

    if (p1 == p1) { //  ������
        cout << "is equalS \n";
    }
    if (p1 != p2) { // �� ������
        cout << "is not equals \n";
    }

    // | ����� ������� 
    Pixel p4 = p3 | p2;
    //cout << "Operator | " << 
    cout << p4;
    cout << endl;


    // |= ����� ������� 
    p2 |= p1; // p2 ����� ����
    cout << p2;
    cout << endl;

    // & ����� ������� 
    Pixel p5 = p4 & p1; // ���� �� ����
    cout << p5;
    cout << endl;

    // &= ����� ������� 
    p5 &= p3; // ���� ��� �����
    cout << p5;
    cout << endl;
    cout << "Pixel test pinish" << endl;




    //=========================================
    //============= ����� �� Image ============
    cout << endl;
    cout << "=============== test of Image =======================\n";
    cout << "The first image is white: \n";
    Image image1(6, 15); // ����� ���� �������
    cout << image1;

    cout << "The second image is: \n";
    Image image2(4, 20, p1); // ����� �����
    cout << image2;
    cout << endl;

    cout << "The three image is: \n";
    Pixel p6(GRAY);
    Image image3(6, 18, p6);
    cout << image3;
    cout << endl;

    cout << "======= Copy constructor ========\n";
    Image copy_image1 = image2; // ����� ���� ����� �����
    cout << "The first image copy constructor is: \n";
    cout << copy_image1;
    cout << endl;

    Image copy_image2(image3); // ����� ���� �����
    cout << "The second image copy constructor is: \n";
    cout << copy_image2;
    cout << endl;

    if (copy_image1 == image2) {
        cout << "the Images are aquls \n";
    }
    if (copy_image2 != image2) {
        cout << "the Images are not aquls \n";
    }


    Image image7(1, 3, Pixel(' '));
    image7 = copy_image2;
    cout << image7;
    cout << endl;

    //======= ������� + ����� ������ =========
    Image image8(10, 8, Pixel(GRAY));
    Image image9(5, 15, Pixel(BLACK));

    // ����� ������ ����� ����
    Image image10, image11;
    image10 = image9 + image8;
    cout << "Image 10\n";
    cout << image10;
    cout << endl;

    // ����� ������ ���� ����
    image11 = image8 + image9;
    cout << "Image 11\n";
    cout << image11;
    cout << endl;

    // ����� ������� +=
    cout << "Image 10 += image11\n";
    image10 += image11 += image8;
    cout << image10;
    cout << endl;
    cout << endl;


    // ����� ������� |
    Image image12(5, 15, Pixel(GRAY));
    Image image13(10, 7, Pixel(BLACK));
    cout << "Image 12\n";
    cout << image12 << endl;
    cout << "Image 13\n";
    cout << image13 << endl;
    Image image14 = image12 | image13;
    cout << "Image12 | image13\n";
    cout << image14;
    cout << endl;
    image14 = image13 | image12;
    cout << "Image13 | image12\n";
    cout << image14;
    cout << endl << endl;

    // ����� ������� |=
    image14 |= image10;
    cout << "image14 ofter |= with image10: \n";
    cout << image14;
    cout << endl;


    // ����� ������� &
    Image image15 = image12 & image13;
    cout << "image12 & image13: \n";
    cout << image15;
    cout << endl;


    // ����� ������� &= 
    image14 = image12 &= image13;
    cout << "image14 ofter &= with image12 &= image13: \n";
    cout << image14;
    cout << endl;

    // ����� ������� ��� ������ *
    cout << "image14 * 5 is: \n";
    Image image16 = image14 * 5;
    cout << image16;
    cout << endl;

    //  ����� ������� ��� ������ * ��� �0
    cout << "image14 * 0 is: \n";
    image16 = image14 * 0;
    cout << image16;
    cout << endl;

    // ����� ������� * ��� �����
    cout << "3 * image14 is: \n";
    image16 = 3 * image14; // ����� �� ���
    cout << image16;
    cout << endl;


    //  ����� ������� ��� ������ �� ����� �������� =*
    cout << "Change the image16 *= 2 is: \n";
    image16 *= 2;
    cout << image16;
    cout << endl;

    // ��� �����
    cout << "Change the 2 *= image16 is: \n";
    2 *= image16;
    cout << image16;
    cout << endl;

    // ����� ������� ������ ~ ���� ���� ����, ��� �����, ���� ���� ����
    Image image17(8, 12, Pixel(WHITE));
    Image image18(8, 12, Pixel(BLACK));
    Image image19(8, 12, Pixel(GRAY));
    Image image20 = image17 + image18 + image19;

    cout << "image befor operator ~ is: \n";
    cout << image20;
    cout << endl;

    cout << "image after operator ~ is: \n";
    Image image21 = ~(image17 + image18 + image19);
    cout << image21;
    cout << endl;

    // � ����� ������� () �� ������ ����� ������
    Pixel& p9 = image21(2, 2);
    Pixel p10(WHITE); // ����� ����� ��� 
    cout << p9 << endl;
    p9 &= p10; // ���� ���� ������ ����� 
    cout << p9 << endl;
    cout << "The image ofter change with reference is: \n";
    cout << image21;
    cout << endl;

    // ����� ������� () �� ������ ���� ����� ����� ������
    const Pixel& p11 = image21(3, 3);
    cout << "The const pixel by reference is: \n";
    cout << p11;
    cout << endl << endl;

    cout << "======= End of the tests, goodbye!!! ======= \n";

    return 0;
}










//#include "Pixel.h"
//#include "Image.h"
//#include "ImageDataStructure.h"
//#include <iostream>
//
//void e()
//{
//	Image matrix3;
//}
//
//int main()
//{
//	const unsigned char BLACK = (unsigned char)219;
//	const unsigned char GRAY = (unsigned char)176;
//	
//	Image matrix1(7, 7, BLACK);
//	Image matrix2(matrix1);
//	e();
//	std::cout << (matrix1);
//	std::cout << (matrix2);
//
//	matrix1(1, 1) = GRAY;
//	matrix1 = matrix1 & matrix2;
//	matrix2 = matrix1 | matrix2;
//	std::cout << (~matrix1) << '\n';
//	std::cout << (matrix1);
//	std::cout << (matrix2);
//
//
//
//	return 0;
//}
