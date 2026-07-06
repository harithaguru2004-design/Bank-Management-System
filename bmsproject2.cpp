#include <iostream>
#include<fstream>
using namespace std;

class BankAccount
{
public:
    int accNo;
    char name[50];
    float balance;
};
void createAccount()
{
    BankAccount b;

    ofstream file("bank.txt", ios::app);

    cout << "Enter Account Number: ";
    cin >> b.accNo;

    cout << "Enter Name: ";
    cin >> b.name;

    cout << "Enter Initial Balance: ";
    cin >> b.balance;

    file << b.accNo << " "
         << b.name << " "
         << b.balance << endl;

    file.close();

    cout << "\nAccount Created Successfully!\n";
}
void displayAccount()
{
    BankAccount b;

    ifstream file("bank.txt");

    cout << "\nAccount Details\n";
    cout << "---------------------------------\n";

    while(file >> b.accNo >> b.name >> b.balance)
    {
        cout << "Account No : " << b.accNo << endl;
        cout << "Name       : " << b.name << endl;
        cout << "Balance    : " << b.balance << endl;
        cout << "---------------------------------\n";
    }

    file.close();
}
void depositMoney()
{
    BankAccount b;
    int acc;
    float amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> acc;

    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while(file >> b.accNo >> b.name >> b.balance)
    {
        if(b.accNo == acc)
        {
            b.balance += amount;
            found = true;
        }

        temp << b.accNo << " "
             << b.name << " "
             << b.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if(found)
        cout << "\nAmount Deposited Successfully!\n";
    else
        cout << "\nAccount Not Found!\n";
}
void withdrawMoney()
{
    BankAccount b;
    int acc;
    float amount;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> acc;

    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    while(file >> b.accNo >> b.name >> b.balance)
    {
        if(b.accNo == acc)
        {
            if(b.balance >= amount)
            {
                b.balance -= amount;
                cout << "\nAmount Withdrawn Successfully!\n";
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
            found = true;
        }

        temp << b.accNo << " "
             << b.name << " "
             << b.balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if(!found)
        cout << "\nAccount Not Found!\n";
}
void checkBalance()
{
    BankAccount b;
    int acc;
    bool found = false;

    cout << "Enter Account Number: ";
    cin >> acc;

    ifstream file("bank.txt");

    while(file >> b.accNo >> b.name >> b.balance)
    {
        if(b.accNo == acc)
        {
            cout << "\nAccount Number : " << b.accNo << endl;
            cout << "Account Holder : " << b.name << endl;
            cout << "Current Balance: " << b.balance << endl;
            found = true;
            break;
        }
    }

    file.close();

    if(!found)
        cout << "\nAccount Not Found!\n";
}
int main()
{
    int choice;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                createAccount();
                break;

            case 2:
                displayAccount();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                checkBalance();
                break;


            case 6:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
