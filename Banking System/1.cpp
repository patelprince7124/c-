#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string holderName;

private:
    double balance;

public:
    BankAccount(int acc, string name, double bal)
    {
        accountNumber = acc;
        holderName = name;
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit Successful!\n";
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double bal)
    {
        balance = bal;
    }

    virtual void calculateInterest()
    {
        cout << "No Interest\n";
    }

    virtual void displayAccountInfo()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nHolder Name    : " << holderName;
        cout << "\nBalance        : " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int acc, string name, double bal, double rate)
        : BankAccount(acc, name, bal)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        double interest = getBalance() * interestRate / 100;
        cout << "Interest = " << interest << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int acc, string name, double bal, double limit)
        : BankAccount(acc, name, bal)
    {
        overdraftLimit = limit;
    }

    void calculateInterest()
    {
        cout << "Checking Account has no interest.\n";
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;

public:
    FixedDepositAccount(int acc, string name, double bal, int t)
        : BankAccount(acc, name, bal)
    {
        term = t;
    }

    void calculateInterest()
    {
        double interest = getBalance() * 0.08 * term / 12;
        cout << "Fixed Deposit Interest = " << interest << endl;
    }
};

int main()
{
    int choice, acc;
    string name;
    double bal, rate, amount, limit;
    int term;

    BankAccount *account = NULL;

    do
    {
        cout << "\n===== BANKING SYSTEM =====";
        cout << "\n1. Savings Account";
        cout << "\n2. Checking Account";
        cout << "\n3. Fixed Deposit";
        cout << "\n4. Deposit";
        cout << "\n5. Withdraw";
        cout << "\n6. Display";
        cout << "\n7. Calculate Interest";
        cout << "\n8. Exit";
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Account Number : ";
            cin >> acc;
            cout << "Holder Name : ";
            cin >> name;
            cout << "Balance : ";
            cin >> bal;
            cout << "Interest Rate : ";
            cin >> rate;
            account = new SavingsAccount(acc, name, bal, rate);
            cout << "Savings Account Created Successfully!\n";
            break;

        case 2:
            cout << "Account Number : ";
            cin >> acc;
            cout << "Holder Name : ";
            cin >> name;
            cout << "Balance : ";
            cin >> bal;
            cout << "Overdraft Limit : ";
            cin >> limit;
            account = new CheckingAccount(acc, name, bal, limit);
            cout << "Checking Account Created Successfully!\n";
            break;

        case 3:
            cout << "Account Number : ";
            cin >> acc;
            cout << "Holder Name : ";
            cin >> name;
            cout << "Balance : ";
            cin >> bal;
            cout << "Term (Months) : ";
            cin >> term;
            account = new FixedDepositAccount(acc, name, bal, term);
            cout << "Fixed Deposit Account Created Successfully!\n";
            break;

        case 4:
            if (account != NULL)
            {
                cout << "Deposit Amount : ";
                cin >> amount;
                account->deposit(amount);
            }
            else
            {
                cout << "Create an account first!\n";
            }
            break;

        case 5:
            if (account != NULL)
            {
                cout << "Withdraw Amount : ";
                cin >> amount;
                account->withdraw(amount);
            }
            else
            {
                cout << "Create an account first!\n";
            }
            break;

        case 6:
            if (account != NULL)
            {
                account->displayAccountInfo();
            }
            else
            {
                cout << "Create an account first!\n";
            }
            break;

        case 7:
            if (account != NULL)
            {
                account->calculateInterest();
            }
            else
            {
                cout << "Create an account first!\n";
            }
            break;

        case 8:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 8);

    delete account;

    return 0;
}