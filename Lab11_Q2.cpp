/*
    ID          : 63011119
    Name        : Chakrin Deesit
    Lab No      : 11
    Question No : 2
    Date        : 01/04/2021
*/

#include <iostream>
#include <memory>
using namespace std;

class Customer {
public: virtual string createMail() = 0;
};

class RegularCustomer : public Customer {
public: string createMail() { return "\nRegular Customer\n"; }
};

class MountainCustomer : public Customer {
public: string createMail() { return "\nMountain Customer\n"; }
};

class DelinquentCustomer : public Customer {
public: string createMail() { return "\nDelinquent Customer\n"; }
};

class CustomerMailApplication {
private:
    unique_ptr<Customer> customer;
    void getCustomerTypeFromUser(string custType) {
        if (custType == "regular") {
            unique_ptr<Customer> temp = make_unique<RegularCustomer>();
            customer = move(temp);
        }
        else if (custType == "mountain") {
            unique_ptr<Customer> temp = make_unique<MountainCustomer>();
            customer = move(temp);
        }
        else {
            unique_ptr<Customer> temp = make_unique<DelinquentCustomer>();
            customer = move(temp);
        }
    }
public:
    void generateMail(string custType) {
        getCustomerTypeFromUser(custType);
        cout << customer->createMail() << endl;
    }
};

int main() {
    CustomerMailApplication app;
    int choice;
    string custType;
    cout << "1. Regular\n2. Mountain\n3. Delinquent\n0. Exit\nYour choice: ";
    cin >> choice;
    while (choice != 0) {
        if (choice == 1) { custType = "regular"; }
        else if (choice == 2) { custType = "mountain"; }
        else { custType = "delinquent"; }
        if (choice != 0 && choice <= 3) { app.generateMail(custType); }
        else { break; }
        cout << "1. Regular\n2. Mountain\n3. Delinquent\n0. Exit\nYour choice: ";
        cin >> choice;
    }
    cout << "Good bye" << endl;
    return 0;
}
