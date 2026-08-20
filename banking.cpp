/*
Assignment 1
lab - OOPL
Problem Statement = Implement a BAnking System
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount
{
private:
  string depositorName;
  long accountNumber;
  double balance;
  string accountType;
  bool isActive;

public:
  // Default Constructor
  BankAccount()
  {
    depositorName = "N/A";
    accountNumber = 0;
    balance = 0.0;
    accountType = "Savings";
    isActive = false;
  }

  // Function to dynamically initialize/create an account
  void createAccount(string name, long long accNum, double initialBalance, string accType)
  {
    depositorName = name;
    accountNumber = accNum;
    accountType = accType;
    isActive = true;
    if (initialBalance >= 0)
    {
      balance = initialBalance;
    }
    else
    {
      balance = 0.0;
      cout << "Initial balance cannot be negative. Set to 0.0\n";
    }
    cout << "\nAccount created successfully for " << depositorName;
  }

  // Function to deposit money
  void deposit(double amount)
  {
    if (!isActive)
    {
      cout << "\nAccount #" << accountNumber << " is inactive!";
      return;
    }
    if (amount > 0)
    {
      balance += amount;
      cout << "\nCredited " << fixed << setprecision(2) << amount << " INR to Account #" << accountNumber;
    }
    else
    {
      cout << "\nInvalid deposit amount!";
    }
  }

  // Function to withdraw money with balance check
  void withdraw(double amount)
  {
    if (!isActive)
    {
      cout << "\nAccount #" << accountNumber << " is inactive!";
      return;
    }
    if (amount <= 0)
    {
      cout << "\nInvalid withdrawal amount!";
    }
    else if (amount > balance)
    {
      cout << "\nInsufficient Balance! Requested: " << amount << " INR | Available: " << balance << " INR";
    }
    else
    {
      balance -= amount;
      cout << "\nDebited " << fixed << setprecision(2) << amount << " INR from Account #" << accountNumber;
    }
  }

  // Function to close/delete account
  void deleteAccount()
  {
    if (!isActive)
    {
      cout << "\nAccount is already inactive/closed.";
      return;
    }
    if (balance > 0.0)
    {
      cout << "\nOutstanding balance: " << fixed << setprecision(2) << balance
           << " INR. Please withdraw all funds first.";
      return;
    }

    isActive = false;
    cout << "\nAccount #" << accountNumber << " ('" << depositorName << "') closed successfully.";
    depositorName = "CLOSED";
    accountNumber = 0;
    balance = 0.0;
  }

  // Function to display account details
  void display() const
  {
    if (isActive)
    {
      cout << left << setw(15) << accountNumber
           << setw(20) << depositorName
           << setw(12) << accountType
           << fixed << setprecision(2) << balance << " INR\n";
    }
  }

  // Getters
  long long getAccountNumber() const { return accountNumber; }
  bool getIsActive() const { return isActive; }

  // Destructor
  ~BankAccount() {}
};

// Search helper function
int findAccount(const BankAccount bank[], int totalCount, long long targetAcc)
{
  for (int i = 0; i < totalCount; i++)
  {
    if (bank[i].getIsActive() && bank[i].getAccountNumber() == targetAcc)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  const int MAX_ACCOUNTS = 10;
  BankAccount bank[MAX_ACCOUNTS]; // Array of 10 objects
  int accountCount = 0;

  int choice;
  long long targetAcc;
  double amount;
  cout << "\n\n=============================================\n";
  cout << "       BANK ACCOUNT MANAGEMENT SYSTEM        \n";
  cout << "=============================================\n\n\n";

  do
  {

    cout << "\n\n      Menu         \n";
    cout << "1. Create New Account\n";
    cout << "2. Display Account Details\n";
    cout << "3. Deposit Funds\n";
    cout << "4. Withdraw Funds\n";
    cout << "5. Delete / Close Account\n";
    cout << "6. Display All Active Accounts\n";
    cout << "7. Exit\n";
    cout << "Enter Choice (1-7): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      if (accountCount >= MAX_ACCOUNTS)
      {
        cout << "\nMaximum account capacity (10) reached!";
      }
      else
      {
        string name, type;
        long long accNum;
        double initBal;

        cin.ignore();
        cout << "\nEnter Depositor Name: ";
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> accNum;

        if (findAccount(bank, accountCount, accNum) != -1)
        {
          cout << "\nAccount Number already exists!";
          break;
        }

        cout << "Enter Account Type (Savings/Current): ";
        cin >> type;
        cout << "Enter Initial Balance: ";
        cin >> initBal;

        bank[accountCount].createAccount(name, accNum, initBal, type);
        accountCount++;
      }
      break;
    }
    case 2:
    {
      if (accountCount == 0)
      {
        cout << "\nNo accounts created yet!";
        break;
      }
      cout << "Enter Account Number: ";
      cin >> targetAcc;
      int idx = findAccount(bank, accountCount, targetAcc);
      if (idx != -1)
      {
        cout << "\n"
             << left << setw(15) << "ACC NO" << setw(20) << "NAME" << setw(12) << "TYPE" << "BALANCE\n";
        cout << "---------------------------------------------------------\n";
        bank[idx].display();
      }
      else
      {
        cout << "\n[ERROR] Active account not found!";
      }
      break;
    }
    case 3:
    {
      cout << "Enter Account Number: ";
      cin >> targetAcc;
      int idx = findAccount(bank, accountCount, targetAcc);
      if (idx != -1)
      {
        cout << "Enter Deposit Amount: ";
        cin >> amount;
        bank[idx].deposit(amount);
      }
      else
      {
        cout << "\nActive account not found!";
      }
      break;
    }
    case 4:
    {
      cout << "Enter Account Number: ";
      cin >> targetAcc;
      int idx = findAccount(bank, accountCount, targetAcc);
      if (idx != -1)
      {
        cout << "Enter Withdrawal Amount: ";
        cin >> amount;
        bank[idx].withdraw(amount);
      }
      else
      {
        cout << "\nActive account not found!";
      }
      break;
    }
    case 5:
    {
      cout << "Enter Account Number to Close: ";
      cin >> targetAcc;
      int idx = findAccount(bank, accountCount, targetAcc);
      if (idx != -1)
      {
        bank[idx].deleteAccount();
      }
      else
      {
        cout << "\nActive account not found!";
      }
      break;
    }
    case 6:
    {
      if (accountCount == 0)
      {
        cout << "\nNo accounts created yet!";
        break;
      }
      cout << "\n"
           << left << setw(15) << "ACC NO" << setw(20) << "NAME" << setw(12) << "TYPE" << "BALANCE\n";
      cout << "---------------------------------------------------------\n";
      for (int i = 0; i < accountCount; i++)
      {
        bank[i].display();
      }
      break;
    }
    case 7:
      cout << "\nExiting System. Goodbye!\n";
      break;

    default:
      cout << "\nInvalid choice!";
    }
  } while (choice != 7);

  return 0;
}