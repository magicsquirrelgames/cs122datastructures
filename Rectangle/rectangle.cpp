#include "rectangle.hpp"

// CONSTRUCTOR
Rectangle::Rectangle(double newWidth, double newLength)
{
    this->width = newWidth;
    this->length = newLength;    
}

// COPY CONSTRUCTOR
Rectangle::Rectangle(const Rectangle &copy)
{
    this->width = copy.width;
    this->length = copy.length;
}

// DESTRUCTOR
Rectangle::~Rectangle()
{
    cout << "Inside of rectangle destructor: " << *this << endl;
}

Rectangle &Rectangle::operator= (const Rectangle &rhs)
{
    if(this != &rhs)
    {
        this->width = rhs.width;
        this->length = rhs.length;
    }

    return *this;
}

// GET WIDTH
double Rectangle::getWidth() const
{
    return width;
}   

// GET LENGTH
double Rectangle::getLength() const
{
    return length;
}

// SET WIDTH
void Rectangle::setWidth(const double newWidth)
{
    if(newWidth >= 0.0)
    {
        width = newWidth;
    }
    else
    {
        width = 0;
    }
}

// SET LENGTH
void Rectangle::setLength(const double newLength)
{
    if(newLength >= 0.0)
    {
        length = newLength;
    }
    else
    {
        length = 0;
    }
}

// PRINT RECTANGLE
void Rectangle::printRectangle() const
{
    std::cout << "Width: " << width << " Length: " << length << "\n";
}

// NON MEMBER OPERATOR
/*
std::ostream operator<< (std::ostream &lhs, Rectangle &rhs)
{
    lhs << "Width: " << rhs.getWidth() << " Length: " << rhs.getLength();
}
*/