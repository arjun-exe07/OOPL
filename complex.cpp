/*
Assignment 3
lab - OOPL
Problem Statement = Implement operator overloading
*/
#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
  float real, img;

public:
  Complex()
  {
    real = 0;
    img = 0;
  }

  Complex(float r, float i)
  {
    real = r;
    img = i;
  }

  Complex operator+(Complex c)
  {
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
  }

  Complex operator-(Complex c)
  {
    Complex temp;
    temp.real = real - c.real;
    temp.img = img - c.img;
    return temp;
  }

  Complex operator*(Complex c)
  {
    Complex temp;
    temp.real = (real * c.real) - (img * c.img); // ac-bd
    temp.img = (real * c.img) + (img * c.real);  // bc + ad
    return temp;
  }

  Complex operator/(Complex c)
  {
    // a + ib
    // c + id
    Complex temp;
    float denom = (c.real * c.real) + (c.img * c.img); // denominator = c.real^2 + c.img^2

    if (denom == 0)
    {
      cout << "Division by zero (denominator complex number is 0) is not defined." << endl;
      temp.real = 0;
      temp.img = 0;
    }
    else
    {
      temp.real = ((real * c.real) + (img * c.img)) / denom; // ac + bd / c^2 + d^2
      temp.img = ((img * c.real) - (real * c.img)) / denom;  // bc - ad / c^2 + d^2
    }
    return temp;
  }

  Complex operator>(Complex c)
  {
    Complex temp;
    temp.real = real > c.real ? real : c.real;
    temp.img = img > c.img ? img : c.img;
    return temp;
  }

  float magnitude()
  {
    return sqrt(real * real + img * img);
  }

  void display()
  {
    if (img >= 0)
      cout << real << " + " << img << "i" << endl;
    else
      cout << real << " - " << -img << "i" << endl;
  }

  inline void setComplex(float, float);
};

inline void Complex::setComplex(float r, float i)
{
  real = r;
  img = i;
}

int main()
{
  float r1, i1, r2, i2;
  int choice;

  cout << "Enter real and imaginary part of first complex number: ";
  cin >> r1 >> i1;

  cout << "Enter real and imaginary part of second complex number: ";
  cin >> r2 >> i2;

  Complex c1(r1, i1);
  Complex c2(r2, i2);
  Complex result;

  cout << "\nFirst complex number:  ";
  c1.display();
  cout << "Second complex number: ";
  c2.display();

  do
  {
    cout << "\n----- MENU -----\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Magnitude ratio\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      result = c1 + c2;
      cout << "Sum = ";
      result.display();
      break;

    case 2:
      result = c1 - c2;
      cout << "Difference = ";
      result.display();
      break;

    case 3:
      result = c1 * c2;
      cout << "Product = ";
      result.display();
      break;

    case 4:
      result = c1 / c2;
      cout << "Quotient = ";
      result.display();
      break;

    case 5:
      cout << "Magnitude of first complex number: " << c1.magnitude() << endl;
      cout << "Magnitude of second complex number: " << c2.magnitude() << endl;
      break;

    case 6:
      cout << "Exiting program.\n";
      break;

    default:
      cout << "Invalid choice! Please enter a number between 1 and 6.\n";
    }

  } while (choice != 6);

  return 0;
}