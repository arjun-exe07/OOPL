#include <iostream>
#include <string>

using namespace std;

class Television
{
private:
  int modelNumber;
  int screenSize;
  double price;

public:
  Television()
  {
    modelNumber = 0;
    screenSize = 0;
    price = 0.0;
  }
  Television(int m, float s, float p)
  {
    modelNumber = m;
    screenSize = s;
    price = p;
  }

  // Overloaded Extraction Operator
  friend istream &operator>>(istream &in, Television &tv)
  {
    cout << "Enter Television Model Number: ";
    in >> tv.modelNumber;

    cout << "Enter Screen Size in Inches : ";
    in >> tv.screenSize;

    cout << "Enter Television Price : ";
    in >> tv.price;

    tv.check();

    return in;
  }

  // Overloaded Insertion Operator (<< Output)
  friend ostream &operator<<(ostream &out, const Television &tv)
  {
    out << "\n--- Television Details ---\n"
        << "Model Number: " << tv.modelNumber << "\n"
        << "Screen Size:  " << tv.screenSize << " inches\n"
        << "Price:        " << tv.price << "\n";
    return out;
  }

  void check()
  {
    if (modelNumber < 9999 || screenSize < 12 || screenSize > 70 || price < 0 || price > 5000)
    {
      throw -1;
    }
  }
  void resetData()
  {
    modelNumber = 0;
    screenSize = 0;
    price = 0.0;
  }
};

int main()
{
  Television tv;

  try
  {
    cin >> tv;

    cout << tv;
  }
  catch (int n)
  {

    cout << "\nException Caught, Invalid input detected : " << n << endl;
    tv.resetData();

    cout << "\nAfter Exception Handling :" << tv;
  }

  return 0;
}