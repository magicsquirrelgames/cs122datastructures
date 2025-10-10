#include <iostream>

class Complex
{
    public:
        Complex(double real, double imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        Complex add(Complex other);
        void print() const;
        void read();
        double getReal() const {return this->real; };
        double getImaginary() const {return this->imaginary; };
        void setReal(const double value) {this->real = value; };
        void setImaginary(const double value) {this->imaginary = value; };
    private:
        double real;
        double imaginary;
};

Complex add(Complex complex1, Complex complex2);
Complex operator+ (const Complex &lhs, const Complex &rhs);
Complex operator- (const Complex &lhs, const Complex &rhs);
std::istream & operator>> (std::istream &lhs, Complex &rhs);