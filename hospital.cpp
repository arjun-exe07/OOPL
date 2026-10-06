#include <iostream>
#include <string>

using namespace std;

// Base class
class Person
{
protected:
  string name;
  int age;
  string contactNumber;

public:
  Person(string n, int a, string c)
  {
    name = n;
    age = a;
    contactNumber = c;
  }

  virtual ~Person() {} // virtual destructor

  // virtual function
  virtual void display()
  {
    cout << "Name: " << name << "\n"
         << "Age: " << age << "\n"
         << "Contact: " << contactNumber << "\n";
  }
};

class Doctor : public Person
{
private:
  string specialization;
  int experienceYears;

public:
  Doctor(string n, int a, string c, string spec, int exp) : Person(n, a, c)
  {
    specialization = spec;
    experienceYears = exp;
  }

  void display() override
  {
    cout << "--- Doctor Details ---\n";
    Person::display();
    cout << "Specialization: " << specialization << "\n"
         << "Experience: " << experienceYears << " years\n\n";
  }
};

class Nurse : public Person
{
private:
  string department;
  string shift;

public:
  Nurse(string n, int a, string c, string dept, string shft) : Person(n, a, c)
  {
    department = dept;
    shift = shft;
  }

  void display() override
  {
    cout << "--- Nurse Details ---\n";
    Person::display();
    cout << "Department: " << department << "\n"
         << "Shift: " << shift << "\n\n";
  }
};

class Admin : public Person
{
private:
  string designation;
  string department;

public:
  Admin(string n, int a, string c, string desig, string dept) : Person(n, a, c)
  {
    designation = desig;
    department = dept;
  }

  void display() override
  {
    cout << "--- Admin Details ---\n";
    Person::display();
    cout << "Designation: " << designation << "\n"
         << "Department: " << department << "\n\n";
  }
};

int main()
{

  Person *staff[100];
  int count = 0;
  int choice;

  cout << "=-- Hospital Management System --=\n";

  do
  {
    cout << "\n1. Add Doctor\n2. Add Nurse\n3. Add Admin\n4. Display All Staff\n5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cin.ignore();

    if (choice >= 1 && choice <= 3)
    {
      if (count >= 100)
      {
        cout << "=> System Limit Reached! Cannot add more employees.\n";
        continue;
      }

      string name, contact, extra1, extra2;
      int age, exp;

      if (choice == 1)
      {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Contact No: ";
        getline(cin, contact);
        cout << "Enter Specialization: ";
        getline(cin, extra1);
        cout << "Enter Experience (in years): ";
        cin >> exp;
        staff[count++] = new Doctor(name, age, contact, extra1, exp);
      }
      else if (choice == 2)
      {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Contact No: ";
        getline(cin, contact);
        cout << "Enter Department: ";
        getline(cin, extra1);
        cout << "Enter Shift (Day/Night): ";
        getline(cin, extra2);
        staff[count++] = new Nurse(name, age, contact, extra1, extra2);
      }
      else if (choice == 3)
      {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Contact No: ";
        getline(cin, contact);
        cout << "Enter Designation: ";
        getline(cin, extra1);
        cout << "Enter Department: ";
        getline(cin, extra2);
        staff[count++] = new Admin(name, age, contact, extra1, extra2);
      }
      cout << "=> Employee Added Successfully!\n";
    }
    else if (choice == 4)
    {
      if (count == 0)
      {
        cout << "\n No staff members to display.\n";
      }
      else
      {
        cout << "\n";
        cout << "   Hospital Staff Information\n";
        cout << "\n";

        for (int i = 0; i < count; i++)
        {
          staff[i]->display(); // Runtime polymorphism
        }
      }
    }
  } while (choice != 5);

  // Clean up dynamically allocated memory before exiting
  for (int i = 0; i < count; i++)
  {
    delete staff[i];
  }

  return 0;
}