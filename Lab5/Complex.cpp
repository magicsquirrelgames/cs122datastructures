#include "Complex.hpp";

// add (member function)
Complex Complex::add(Complex other)
{
    return Complex(this->getReal() + other.getReal(), this->imaginary + other.getImaginary());
}

// add (non-member function)
Complex add(Complex first, Complex second)
{
    return first.add(second);
}

// non-member add operator
Complex operator+ (const Complex &lhs, const Complex &rhs)
{
    double sumReal = lhs.getReal() + rhs.getReal();
    double sumImaginary = lhs.getImaginary() + rhs.getImaginary();
    return Complex(sumReal, sumImaginary);
}

// overloaded non-member subtraction operator
Complex operator- (const Complex &lhs, const Complex &rhs)
{
    double differenceReal = lhs.getReal() - rhs.getReal();
    double differenceImaginary = lhs.getImaginary() - rhs.getImaginary();
    return Complex(differenceReal, differenceImaginary);
}

// overloaded non-member insert operator
std::ostream &operator << (std::ostream &lhs, const Complex &rrs)
{
    return lhs;
}

// read user input (member function)
void Complex::read()
{
    double realPart = 0;
    double imaginaryPart = 0;
    char character = NULL;
    std::cin >> realPart >> character >> imaginaryPart >> character;
    this->real = realPart;
    this->imaginary = imaginaryPart;
}

// overloaded non-member input operator
std::istream & operator>> (std::istream &lhs, Complex &rhs)
{
    double realPart = 0;
    double imaginaryPart = 0;
    char character = NULL;
    lhs >> realPart >> character >> imaginaryPart >> character;
    rhs.setReal(realPart);
    rhs.setImaginary(imaginaryPart);
}

// print the real and imaginary parts (member function)
void Complex::print() const
{
    std::cout << this->real << "+" << this->imaginary << "i\n";
}
