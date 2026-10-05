/*
Assignment 4
lab - OOPL
Problem Statement = Implement a student Marksheet Report

*/

#include <iostream>
#include <string>
using namespace std;

// Base Class
class Student
{
protected:
  int roll_no;
  string name;
  string student_class;

public:
  void getStudentDetails()
  {
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Class: ";
    getline(cin, student_class);
  }

  void displayStudentDetails()
  {
    cout << "Roll Number  : " << roll_no << endl;
    cout << "Name         : " << name << endl;
    cout << "Class        : " << student_class << endl;
  }

  int getRollNo()
  {
    return roll_no;
  }
};

// Derived Class
class Exam : virtual public Student
{
protected:
  float cia_marks;
  float ese_marks;

public:
  void getExamDetails()
  {
    cout << "Enter CIA Marks: ";
    cin >> cia_marks;
    cout << "Enter ESE Marks: ";
    cin >> ese_marks;
  }

  void displayExamDetails()
  {
    cout << "CIA Marks    : " << cia_marks << endl;
    cout << "ESE Marks    : " << ese_marks << endl;
  }
};

// Derived Class
class Sport : public virtual Student
{
protected:
  string sport_name;
  char sport_grade;

public:
  void getSportDetails()
  {
    cin.ignore();
    cout << "Enter Sport Name: ";
    getline(cin, sport_name);
    cout << "Enter Sports Grade (A/B/C/D): ";
    cin >> sport_grade;
  }

  void displaySportDetails()
  {
    cout << "Sport Name   : " << sport_name << endl;
    cout << "Sports Grade : " << sport_grade << endl;
  }
};

// Final Derived Class
class Result : public Exam, public Sport
{
public:
  void buildGradeSheet()
  {
    getStudentDetails();
    getExamDetails();
    getSportDetails();
  }

  void displayGradeSheet()
  {
    cout << "\n--                       -" << endl;
    displayStudentDetails();
    displayExamDetails();
    cout << "Total Marks  : " << (cia_marks + ese_marks) << endl;
    displaySportDetails();
    cout << "-                         --\n"
         << endl;
  }
};

int main()
{
  Result students[10];
  int studentCount = 0;
  int choice;

  while (true)
  {
    cout << "\nStudent Result system" << endl;

    cout << "1. Create/ Accept details" << endl;
    cout << "2. Display All Records" << endl;
    cout << "3. Search by Roll Number" << endl;
    cout << "4. Update " << endl;
    cout << "5. Delete " << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      if (studentCount < 10)
      {

        students[studentCount].buildGradeSheet();
        studentCount++;
        cout << "Record added successfully!\n";
      }
      else
      {
        cout << "no space remaining\n";
      }
      break;
    }
    case 2:
    {
      if (studentCount == 0)
      {
        cout << "\nNo records found!\n";
      }
      else
      {
        cout << "\n=== ALL STUDENT RECORDS ===" << endl;
        for (int i = 0; i < studentCount; i++)
        {
          students[i].displayGradeSheet();
        }
      }
      break;
    }
    case 3:
    {
      if (studentCount == 0)
      {
        cout << "\nNo records found!\n";
        break;
      }
      int searchRoll;
      bool found = false;
      cout << "\nEnter Roll Number to search: ";
      cin >> searchRoll;

      for (int i = 0; i < studentCount; i++)
      {
        if (students[i].getRollNo() == searchRoll)
        {
          cout << "\nRecord Found!";
          students[i].displayGradeSheet();
          found = true;
          break;
        }
      }
      if (!found)
        cout << "\nStudent with Roll Number " << searchRoll << " not found!\n";
      break;
    }
    case 4:
    {
      if (studentCount == 0)
      {
        cout << "\nNo records found to update!\n";
        break;
      }
      int updateRoll;
      bool found = false;
      cout << "\nEnter Roll Number to update: ";
      cin >> updateRoll;

      for (int i = 0; i < studentCount; i++)
      {
        if (students[i].getRollNo() == updateRoll)
        {
          cout << "\nEnter new details:" << endl;
          students[i].buildGradeSheet();
          cout << "\nRecord updated successfully!\n";
          found = true;
          break;
        }
      }
      if (!found)
        cout << "\nStudent with Roll Number " << updateRoll << " not found!\n";
      break;
    }
    case 5:
    {
      if (studentCount == 0)
      {
        cout << "\nNo records found to delete!\n";
        break;
      }
      int deleteRoll;
      bool found = false;
      cout << "\nEnter Roll Number to delete: ";
      cin >> deleteRoll;

      for (int i = 0; i < studentCount; i++)
      {
        if (students[i].getRollNo() == deleteRoll)
        {

          for (int j = i; j < studentCount - 1; j++)
          {
            students[j] = students[j + 1];
          }
          studentCount--;
          cout << "\nRecord deleted successfully!\n";
          found = true;
          break;
        }
      }
      if (!found)
        cout << "\nStudent with Roll Number " << deleteRoll << " not found!\n";
      break;
    }
    case 6:
    {
      cout << "\nExiting system. Goodbye!\n";
      return 0;
    }
    default:
      cout << "\nInvalid choice! Please select between 1 and 6.\n";
    }
  }
  return 0;
}