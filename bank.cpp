#include <iostream>
using namespace std;
class BankAccount {
private:
  double account_number;
  double balance;
public:
  BankAccount(double account_number, double balance = 0.0) {
    this->account_number = account_number;
    this->balance = balance;
  }
  void deposit(double amount) {
    balance += amount;
    cout << "Deposited Rs." << amount << ". New balance: Rs." << balance << endl;
  }
  bool withdraw(double amount) {
    if (balance < amount) {
      cout << "Insufficient funds. Available balance: Rs." << balance << endl;
      return false;
    }
    balance -= amount;
    cout << "Withdrew Rs." << amount << ". New balance: Rs." << balance << endl;
    return true;
  }
  double get_balance() const {
    return balance;
  }
};
int main() {
  double account_number;
  double balance;
  cout << "Enter account number: ";
  cin >> account_number;
  cout << "Enter initial balance: ";
  cin >> balance;
  BankAccount account(account_number, balance);
  int choice;
  while (true) {
    cout << endl;
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Check balance" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter deposit amount: ";
        double deposit_amount;
        cin >> deposit_amount;
        account.deposit(deposit_amount);
        break;
      case 2:
        cout << "Enter withdrawal amount: ";
        double withdrawal_amount;
        cin >> withdrawal_amount;
        account.withdraw(withdrawal_amount);
        break;
      case 3:
        cout << "Current balance: Rs." << account.get_balance() << endl;
        break;
      case 4:
        cout << "Thank you for using our service!!" << endl;
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
  }
  return 0;
}
