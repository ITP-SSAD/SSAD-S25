#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string ownerName;

public:
    // Default constructor
    Account() = default;

    // Parameterized constructor
    Account(int accNum, double initialBalance, string name)
        : accountNumber(accNum), balance(initialBalance), ownerName(move(name)) {}

    // Deleted copy constructor and copy assignment operator
    Account(const Account &) = delete;
    Account &operator=(const Account &) = delete;

    // Deposit money into the account
    void deposit(double amount)
    {
        balance += amount;
    }

    // Withdraw money from the account
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Get current balance
    double getBalance() const
    {
        return balance;
    }

    // Get account number
    int getAccountNumber() const
    {
        return accountNumber;
    }

    // Get owner's name
    const string &getOwnerName() const
    {
        return ownerName;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNum, double initialBalance, string name, double rate)
        : Account(accNum, initialBalance, move(name)), interestRate(rate) {}

    // Calculate interest
    void calculateInterest()
    {
        double interest = balance * interestRate / 100.0;
        deposit(interest);
    }

    // Get interest rate
    double getInterestRate() const
    {
        return interestRate;
    }
};

int main()
{
    // Usage example
    SavingsAccount savings(123456, 1000.0, "John Doe", 2.5);
    savings.deposit(500.0);
    savings.withdraw(200.0);
    savings.calculateInterest();

    cout << "Account Number: " << savings.getAccountNumber() << endl;
    cout << "Owner's Name: " << savings.getOwnerName() << endl;
    cout << "Current Balance: " << savings.getBalance() << endl;
    cout << "Interest Rate: " << savings.getInterestRate() << "%" << endl;

    return 0;
}