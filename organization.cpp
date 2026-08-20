/*
Class Learning
Written during C++ learning theory.
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Person
{
  char *name, blood_group[3];
  int age, aadhar;
  long long driving_license;
  string address;
  static int count;

public:
  Person()
  {
    name = new char;
    strcpy(name, "N/A");
    strcpy(blood_group, "N/A");
    age = 0;
    aadhar = 0;
    driving_license = 0;
    address = "Kopargaon";
  }

  Person(const char *n, int a = 18, int ad = 1000, long long dl = 10000, string add = "Nashik", const char *bg = "A")
  {
    name = new char;
    strcpy(name, n);
    strcpy(blood_group, bg);
    age = a;
    aadhar = ad;
    driving_license = dl;
    address = add;
  }

  Person(Person &p)
  {
    name = new char;
    strcpy(name, p.name);
    age = p.age;
    aadhar = p.aadhar;
    driving_license = p.driving_license;
    address = p.address;
    strcpy(blood_group, p.blood_group);
  }

  ~Person()
  {
    delete name;
  }

  void accept();
  void display()
  {
    cout << left << setw(15) << name << setw(15) << address << setw(15) << age << setw(15) << aadhar << setw(15) << driving_license << setw(15) << blood_group << endl;
  }

  friend void search(Person[], int, const char *);

  int getCount()
  {
    return count;
  }
} p[10];

int Person::count = 0;

int main()
{
  int choice;

  do
  {
    choice;
    cout << "1. Accept Details" << endl;
    cout << "2. Search Details" << endl;
    cout << "3. Display All Details" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      p[p[0].getCount()].accept();
      break;

    case 2:
    {
      char name[50];
      cout << "Enter name to search: ";
      cin >> name;
      search(p, p[0].getCount(), name);

      break;
    }
    case 3:
      if (p[0].getCount() == 0)
      {
        cout << "No records found!" << endl;
        break;
      }

      cout << left << setw(15) << "Name " << setw(15) << "Address " << setw(15) << "Age " << setw(15) << "Aadhar " << setw(15) << "Driving License " << setw(15) << "Blood Group " << endl;
      for (int i = 0; i < p[0].getCount(); i++)
      {
        p[i].display();
      }
      break;

    case 4:
      cout << "Exiting..." << endl;
      break;

    default:
      cout << "Invalid choice!" << endl;
    }
  } while (choice != 4);
  return 0;
}

inline void Person::accept()
{
  count++;
  cout << "Enter Personal Details: ";
  cin >> name >> age >> aadhar >> driving_license >> address >> blood_group;
}

void search(Person p[], int n, const char *name)
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(p[i].name, name) == 0)
    {
      cout << "Record Found: " << endl;
      p[i].display();
      return;
    }
  }
  cout << "Record Not Found" << endl;
}