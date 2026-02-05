# BankAccount Class

A C++ class for simulating basic banking operations for multiple accounts.

## Data Dictionary

| Attribute           | Data Type     | Description                                |
|---------------------|---------------|--------------------------------------------|
| `accountNumber`     | `std::string` | Unique identifier for the account.         |
| `accountHolderName` | `std::string` | The name of the account owner.             |
| `balance`           | `double`      | The current financial balance in the account.|

## Methods List

| Method Signature                                     | Return Type   | Description                                |
|------------------------------------------------------|---------------|--------------------------------------------|
| `BankAccount()`                                      | (Constructor) | Default constructor.                       |
| `BankAccount(accNum, name, balance)`                 | (Constructor) | Parameterized constructor.                 |
| `getAccountNumber() const`                           | `std::string` | Returns the account number.                |
| `getAccountHolderName() const`                       | `std::string` | Returns the holder's name.                 |
| `getBalance() const`                                 | `double`      | Returns the current balance.               |
| `setAccountHolderName(name)`                         | `void`        | Updates the account holder's name.         |
| `deposit(amount)`                                    | `void`        | Adds money to the balance.                 |
| `withdraw(amount)`                                   | `bool`        | Removes money if sufficient funds exist.   |
