#include <iostream>
using namespace std;

class Complex
{

private:
  int real;
  int imag;

public:
  Complex(int re = 0, int im = 0) : real(re), imag(im) {}
  int getReal() const;
  int getImag() const;
  void print() const;
  Complex add(Complex other) const;
  Complex operator+(Complex other) const;
};

int Complex::getReal() const
{
  return real;
}

int Complex::getImag() const
{
  return imag;
}

void Complex::print() const
{
  cout << real << " + " << imag << "i" << endl;
}

Complex add(Complex first, Complex second)
{
  return Complex(first.getReal() + second.getReal(), first.getImag() + second.getImag());
}

Complex Complex::add(Complex other) const
{
  return Complex(real + other.real, imag + other.imag);
}

// Complex operator+(Complex first, Complex second)
// {
//     return Complex(first.getReal() + second.getReal(), first.getImag() + second.getImag());
// }

Complex Complex::operator+(Complex other) const
{
  return Complex(real + other.real, imag + other.imag);
}

void operator<<(ostream &out, const Complex &c)
{
  // c.print();
  out << c.getReal() << " + " << c.getImag() << "i";
}

int main()
{
  Complex x(1, 2), y(3, 4);
  Complex z(5, 6);

  x.print();

  add(x, y).print();
  x.add(y).print();
  cout << "____________" << endl;
  (x + y).print();

  cout << x;

  return 0;
}