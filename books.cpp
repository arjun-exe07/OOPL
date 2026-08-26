/*
Assignment 2
lab - OOPL
Problem Statement = Implement a Book Management System
*/

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

class Book
{
private:
  char *name, *author;
  float price;
  string publisher;
  int quantity;

public:
  Book()
  {
    name = new char[100];
    author = new char[100];
    price = 0.0;
    publisher = "N/A";
    quantity = 0;
  }

  Book(const char *n, const char *a, float p = 0.0, string pub = "N/A", int q = 0)
  {
    name = new char[100];
    author = new char[100];
    strcpy(name, n);
    strcpy(author, a);
    price = p;
    publisher = pub;
    quantity = q;
  }

  void accept()
  {
    char n[100], a[100];
    cout << "Enter the Book Name :";
    cin.ignore();
    cin.getline(n, 100);
    strcpy(name, n);

    cout << "Enter the Book Author :";
    cin.getline(a, 100);
    strcpy(author, a);

    cout << "Enter the book price :";
    cin >> price;

    cout << "Enter the publisher name :";
    cin.ignore();
    getline(cin, publisher);

    cout << "Enter the quantity of books :";
    cin >> quantity;
  }
  void display();
  void update();
  friend void deleteBook(Book b[], int &bookCount, int idx);

  friend int search(Book[], const char *, const char *, int);

  void sellBook(int qty)
  {
    if (qty <= quantity)
    {
      quantity -= qty;
      cout << "\nSold " << qty << " copies of " << name;
    }
    else
    {
      cout << "\nInsufficient stock for " << name;
    }
  }
  ~Book()
  {
    delete[] name;
    delete[] author;
  }
};

inline void Book::display()
{
  cout << left << setw(20) << name << setw(20) << author << setw(10) << price << setw(20) << publisher << setw(10) << quantity << endl;
}

int search(Book b[], const char *n, const char *a, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (strcmp(b[i].name, n) == 0 && strcmp(b[i].author, a) == 0)
    {
      return i;
    }
  }
  return -1;
}

Book b[10];
int main()
{
  int choice;
  int bookCount = 0;

  do
  {
    cout << "\n\n      Menu         \n";
    cout << "1. Accept New Book\n";
    cout << "2. Display Book Details\n";
    cout << "3. Update Book Details\n";
    cout << "4. Delete Book\n";
    cout << "5. Search Book\n";
    cout << "6. Display All Books\n";
    cout << "7. Sell Book\n";
    cout << "8. Exit\n";
    cout << "Enter Choice (1-8): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      if (bookCount < 10)
      {
        b[bookCount++].accept();
      }
      else
      {
        cout << "\nBook limit reached!";
      }
      break;
    }

    case 2:
    {
      char n[100], a[100];
      cout << "Enter Book Name: ";
      cin.ignore();
      cin.getline(n, 100);
      cout << "Enter Book Author: ";
      cin.getline(a, 100);
      int idx = search(b, n, a, bookCount);
      if (idx != -1)
      {
        b[idx].display();
      }
      else
      {
        cout << "\nBook not found!";
      }
      break;
    }

    case 3:
    {
      char n[100], a[100];
      cout << "Enter Book Name: ";
      cin.ignore();
      cin.getline(n, 100);
      cout << "Enter Book Author: ";
      cin.getline(a, 100);
      int idx = search(b, n, a, bookCount);
      if (idx != -1)
      {
        b[idx].update();
      }
      else
      {
        cout << "\nBook not found!";
      }
      break;
    }

    case 4:
    {
      char n[100], a[100];
      cout << "Enter Book Name: ";
      cin.ignore();
      cin.getline(n, 100);
      cout << "Enter Book Author: ";
      cin.getline(a, 100);
      int idx = search(b, n, a, bookCount);
      if (idx != -1)
      {
        deleteBook(b, bookCount, idx);
        cout << "\nBook deleted successfully!";
      }
      else
      {
        cout << "\nBook not found!";
      }

      break;
    }

    case 5:
    {
      char n[100], a[100];
      cout << "Enter Book Name: ";
      cin.ignore();
      cin.getline(n, 100);
      cout << "Enter Book Author: ";
      cin.getline(a, 100);
      int idx = search(b, n, a, bookCount);
      if (idx != -1)
      {
        b[idx].display();
      }
      else
      {
        cout << "\nBook not found!";
      }
      break;
    }

    case 6:
    {

      for (int idx = 0; idx < bookCount; idx++)
      {
        cout << "---------------------------------------------------------\n";
        b[idx].display();
      }
      break;
    }

    case 7:
    {
      char n[100], a[100];
      cout << "Enter Book Name: ";
      cin.ignore();
      cin.getline(n, 100);
      cout << "Enter Book Author: ";
      cin.getline(a, 100);
      int idx = search(b, n, a, bookCount);
      if (idx != -1)
      {
        int qty;
        cout << "Enter the quantity to sell: ";
        cin >> qty;
        b[idx].sellBook(qty);
      }
      else
      {
        cout << "\nBook not found!";
      }
      break;
    }

    case 8:
    {
      cout << "\nExiting the program. Goodbye!\n";
      break;
    }

    default:
    {
      cout << "\nInvalid choice!";
      break;
    }
    }

  } while (choice != 8);
  return 0;
}

void Book::update()
{
  cout << "Enter the new price: ";
  cin >> price;
  cout << "Enter the new quantity: ";
  cin >> quantity;
}

void deleteBook(Book b[], int &bookCount, int idx)
{
  for (int i = idx; i < bookCount - 1; i++)
  {
    b[i] = b[i + 1];
  }
  bookCount--;
}
