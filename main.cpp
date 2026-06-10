#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BankAccount
{   private:
    string name;
    int accountNumber;
    double balance;
    int pin;

    public:
    BankAccount()
    { balance = 0;
    }

    void createAccount()
    {   cout << "\n===== CREATE ACCOUNT =====\n";
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Set a 4-digit PIN: ";
        cin >> pin;
        cout << "Account Created Successfully!\n";
         
        ofstream file("account.txt");
        file << name << endl;
        file << accountNumber << endl;
        file << balance;
        file.close();
    }

    void deposit()
    {   double amount;
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;
    if (enteredPin == pin)
    {   cout << "\nEnter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }
    else
    {   cout << "Incorrect PIN!" << endl;
    }
    }

    void withdraw()
    {   double amount;
        int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;
    if (enteredPin == pin)
    {   cout << "\nEnter amount to withdraw: ";
        cin >> amount;
        if (amount > balance)
        { cout << "Insufficient Balance!\n";
        }
        else
        {   balance -= amount;
            cout << "Withdrawal Successful.\n";
        }
    }
    else
    {   cout << "Incorrect PIN!" << endl;
    }
    }

    void checkBalance()
    {   int enteredPin;
        cout << "Enter PIN: ";
        cin >> enteredPin;
    if (enteredPin == pin)
    {   cout << "\nCurrent Balance = Rs. " << balance << endl;
    }
    else
    {   cout << "Incorrect PIN!" << endl;
    }
    }

    void displayDetails()
    {  int enteredPin;
       cout << "Enter PIN: ";
       cin >> enteredPin;
    if (enteredPin == pin)
    {  cout << "\n===== ACCOUNT DETAILS =====\n";
       cout << "Account Holder : " << name << endl;
       cout << "Account Number : " << accountNumber << endl;
       cout << "Balance : Rs. " << balance << endl;    
    }
    else
    {  cout << "Incorrect PIN!" << endl;
    } 
    }
};

int main()
{   BankAccount account;
    int choice;

    while (true)
    {   cout << "\n========== BANKING SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {case 1:
            account.createAccount();
            break;
        case 2:
            account.deposit();
            break;
        case 3:
            account.withdraw();
            break;
        case 4:
            account.checkBalance();
            break;
        case 5:
            account.displayDetails();
            break;
        case 6:
            cout << "\nThank you for using the Banking System.\n";
            return 0;
        default:
            cout << "Invalid Choice!\n";
        }
    }
    return 0;
}