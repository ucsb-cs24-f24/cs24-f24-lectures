#include <iostream>
using namespace std;

class Complex
{
private:
    double imag;
    double real;

public:
    Complex(double re = 0, double im = 0) : real(re), imag(im) {};
    ~Complex()
    {
        cout << "Bye" << endl;
    }; // Default destructor
    double getReal() const { return real; };
    double getImag() const { return imag; };
    void print() const;
    // Complex operator+(Complex other);
};

Complex operator+(Complex first, Complex second)
{
    return Complex(first.getReal() + second.getReal(), first.getImag() + second.getImag());
}

// Complex Complex::operator+(Complex other)
// {
//     return Complex(real + other.getReal(), imag + other.getImag());
// }

void Complex::print() const
{
    cout << real << " + " << imag << "i" << endl;
}

// void operator<<(ostream &out, const Complex &c)
// {
//     c.print();
// }

ostream &operator<<(ostream &out, const Complex &c)
{
    // c.print();
    out << c.getReal() << " + " << c.getImag() << "i";
    return out;
}

void foo()
{
    // memory leak
    Complex *p = new Complex(1, 3);
}

Complex *bar()
{
    Complex x, y;
    Complex *p = new Complex(1, 3);

    return p;
}

int main()

{
    Complex *p = bar();
    delete p;
    p = bar();
    delete p;

    // foo();
    // Complex x(3, 4), y(1, 2);
    // Complex w(1, 2);
    // // x.print();
    // Complex z = x + y + w;
    // // z.print();
    // // cout << z;

    // cout << x << y << z;

    return 0;
}