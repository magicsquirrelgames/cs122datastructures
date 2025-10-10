// HOW TO RUN CODE
// gcc main.cpp rectangle.cpp -o rectangle
// ./rectangle

#include "rectangle.hpp"

int main()
{
    /*
    int n1 = 10;
    int& refN1 = n1;

    refN1 = 25;

    cout << "n1: " << n1 << " refN1: " << refN1 << endl;
    cout << "address n1: " << &n1 << " address refN1: " << &refN1 << endl;
    */

    Rectangle rectangle1 (5.6, 7.4);

    double newWidth = 0;
    double newLength = 0;

    std::cout << "Enter a width and length for the rectangle: ";
    std::cin >> newWidth;
    std::cin >> newLength;

    rectangle1.setWidth(newWidth);
    rectangle1.setLength(newLength);

    rectangle1.printRectangle();

    return 0;
}