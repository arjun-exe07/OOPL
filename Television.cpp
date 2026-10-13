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

  Television(int m, int s, double p)
  {
    modelNumber = m;
    screenSize = s;
    price = p;
  }

  // Overloaded Extraction Operator
  friend istream &operator>>(istream &in, Television &tv)
  {
    cout << "Enter Television Model Number : ";
    in >> tv.modelNumber;

    cout << "Enter Screen Size in Inches: ";
    in >> tv.screenSize;

    cout << "Enter Television Price : ";
    in >> tv.price;

    tv.check();

    return in;
  }

  // Overloaded Insertion Operator (<< Output)
  friend ostream &operator<<(ostream &out, const Television &tv)
  {
    out << "Model Number: " << tv.modelNumber
        << " | Screen Size: " << tv.screenSize << " inches"
        << " | Price: " << tv.price;
    return out;
  }

  void check()
  {

    if (modelNumber < 1000 || modelNumber > 9999 || screenSize < 12 || screenSize > 70 || price < 0 || price > 5000)
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

  void updateData(int m, int s, double p)
  {
    modelNumber = m;
    screenSize = s;
    price = p;
    check();
  }
};

int main()
{
  const int MAX_TV = 10;
  Television tvList[MAX_TV];
  int count = 0;
  int choice;

  do
  {
    cout << "\n";
    cout << "   TELEVISION RECORD SYSTEM     \n";

    cout << "1. Create (Add Television)\n";
    cout << "2. Read (Display All Televisions)\n";
    cout << "3. Update Television\n";
    cout << "4. Delete Television\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      if (count >= MAX_TV)
      {
        cout << "\n[Error] Storage full! Maximum limit of 10 televisions reached.\n";
        break;
      }

      Television tempTv;
      try
      {
        cin >> tvList[count];
        count++;
        cout << "Television added successfully!\n";
      }
      catch (int n)
      {
        cout << "\nInvalid input detected: " << n << endl;

        tvList[count].resetData();
        count++;
      }
      break;
    }

    case 2:
    {
      if (count == 0)
      {
        cout << "\nNo televisions found in the system.\n";
      }
      else
      {
        cout << "\n--- Television Inventory  ---\n";
        for (int i = 0; i < count; i++)
        {
          cout << "\nIndex #" << i << " :: \n"
               << tvList[i] << endl;
        }
      }
      break;
    }

    case 3:
    {
      if (count == 0)
      {
        cout << "\nNo televisions available to update.\n";
        break;
      }

      int index;
      cout << "\nEnter index of television to update: ";
      cin >> index;

      if (index < 0 || index >= count)
      {
        cout << "Invalid index selected.\n";
        break;
      }

      int newModel, newSize;
      double newPrice;
      cout << "Enter new Model Number (4 digits): ";
      cin >> newModel;
      cout << "Enter new Screen Size (12 to 70): ";
      cin >> newSize;
      cout << "Enter new Price ($): ";
      cin >> newPrice;

      try
      {
        tvList[index].updateData(newModel, newSize, newPrice);
        cout << "Television updated successfully!\n";
      }
      catch (int n)
      {
        cout << "\nInvalid update data : " << n << endl;
        tvList[index].resetData();
        cout << "Input failed validation. Record at index " << index << " has been reset to 0.\n";
      }
      break;
    }

    case 4:
    {
      if (count == 0)
      {
        cout << "\nNo televisions available to delete.\n";
        break;
      }

      int index;
      cout << "\nEnter index of television to delete : ";
      cin >> index;

      if (index < 0 || index >= count)
      {
        cout << "Invalid index selected.\n";
        break;
      }

      for (int i = index; i < count - 1; i++)
      {
        tvList[i] = tvList[i + 1];
      }
      tvList[count - 1] = Television();
      count--;

      cout << "Television deleted successfully!\n";
      break;
    }

    case 5:
      cout << "\nExiting program. Goodbye!\n";
      break;

    default:
      cout << "\nInvalid choice! Please enter a number between 1 and 5.\n";
    }
  } while (choice != 5);

  return 0;
}