#include <vector>
#include <iostream>
#include <string>

class BankAccount {
    public:
        BankAccount(const std::string holderName, const int value) : holderName(holderName) {
            insert(value);
        }

        void withDraw(const int amount) {
            value -= amount;
        }

        void insert(const int amount) {
            value += amount;
        }

        const std::string holderName;
        int value{0};

};

class Bank {
    public:
        Bank(){} // Default constructor

        void registerBankAccount(BankAccount* newAccount) {
            bankAccounts.push_back(newAccount);
        }

        BankAccount* getBankAccountByHolder(const std::string holderName) {
            for (auto it = bankAccounts.begin(); it != bankAccounts.end(); ++it) {
                if ((*it)->holderName == holderName) {
                    return (*it);
                }
            }
            return nullptr;
        }


    private:
        std::vector<BankAccount*> bankAccounts;
};

int main() {
    Bank* const bank = new Bank;
    BankAccount* const johnAccount = new BankAccount("John Doe", 5000);
    BankAccount* const sarahAccount = new BankAccount("Sarah Doe", 6000);
    
    bank->registerBankAccount(johnAccount);
    bank->registerBankAccount(sarahAccount);

    sarahAccount->withDraw(1000);
    johnAccount->withDraw(500);

    if (bank->getBankAccountByHolder("John Doe") != nullptr) {
        std::cout << bank->getBankAccountByHolder("John Doe")->value << std::endl;
    } else {
        std::cout << "No such account name exists!\n";
    }

    delete bank;
    delete johnAccount;
    delete sarahAccount;

    return 0;
}