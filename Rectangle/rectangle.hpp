#include <iostream>
#include <string>

// not prefered
using namespace std;

// preferable
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Rectangle
{
public:
    Rectangle(double newWidth = 0, double newLength = 0);

    // rule of three - overloaded assignment operator

    // copy constructor
    // defines how a Rectangle should be copied when it is passed to a function
    Rectangle(const Rectangle &copy);

    // destructor
    // invoked when a rectangle goes out of scope
    ~Rectangle();

    // overloaded assignment operator
    Rectangle &operator= (const Rectangle &rhs);

    // getters
    double getWidth() const;
    double getLength() const;

    // setters
    void setWidth(const double newWidth);
    void setLength(const double newLength);

    void printRectangle() const;

private:
    double width;
    double length;
};

std::ostream operator<< (std::ostream &lhs, Rectangle &rhs);