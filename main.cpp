//Jwalia Raval
//2/4/25
//Bank account code




#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
// Bank Account class
class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
//Balance with banka ccount name and holder. 
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0.0) {}

    BankAccount(std::string accNum, std::string name, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialBalance >= 0 ? initialBalance : 0;
    }

    std::string getAccountNumber() const { return accountNumber; }
    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    void setAccountHolderName(std::string name) { accountHolderName = name; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful." << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful." << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds or invalid amount." << std::endl;
            return false;
        }
    }
};
//Makes sure the input is write. 
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
// main
int main() {
    std::vector<BankAccount> accounts;
    int choice;

    while (true) {
        std::cout << "\n--- Bank Management System ---\n";
        std::cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. View All Accounts\n5. Exit\n";
        std::cout << "Enter choice: ";

        if (!(std::cin >> choice)) {
            clearInput();
            continue;
        }

        if (choice == 5) break;

        if (choice == 1) {
            std::string accNum, name;
            double initialBalance;
            std::cout << "Enter Account Number: ";
            std::cin >> accNum;
            std::cout << "Enter Account Holder Name: ";
            clearInput();
            std::getline(std::cin, name);
            std::cout << "Enter Initial Balance: ";
            std::cin >> initialBalance;
            accounts.emplace_back(accNum, name, initialBalance);
        } else if (choice == 2 || choice == 3) {
            std::string accNum;
            std::cout << "Enter Account Number: ";
            std::cin >> accNum;
            bool found = false;
            for (auto &acc : accounts) {
                if (acc.getAccountNumber() == accNum) {
                    double amount;
                    std::cout << "Enter amount: ";
                    std::cin >> amount;
                    if (choice == 2) acc.deposit(amount);
                    else acc.withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Account not found." << std::endl;
        } else if (choice == 4) {
            std::cout << std::fixed << std::setprecision(2);
            for (const auto &acc : accounts) {
                std::cout << "Acc: " << acc.getAccountNumber() << " | Name: " << acc.getAccountHolderName()
                          << " | Balance: $" << acc.getBalance() << std::endl;
            }
        }
    }
    return 0;
}
//That's it. 
