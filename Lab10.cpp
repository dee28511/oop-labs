/*
    ID          : 63011119
    Name        : Chakrin Deesit
    Lab No      : 10
    Question No : 1
    Date        : 25/03/2021
*/

#include <iostream>
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
private: Customer* customer; string type;
public:
    void generateMail() {
        cout << customer->createMail() << endl;
        if (type == "regular") { delete (RegularCustomer*)customer; }
        else if (type == "mountain") { delete (MountainCustomer*)customer; }
        else { delete (DelinquentCustomer*)customer; }
    }
    void getCustomerTypeFromUser(string custType) {
        type = custType;
        if (type == "regular") { customer = new RegularCustomer(); }
        else if (type == "mountain") { customer = new MountainCustomer(); }
        else { customer = new DelinquentCustomer(); }
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
        app.getCustomerTypeFromUser(custType);
        app.generateMail();
        cout << "1. Regular\n2. Mountain\n3. Delinquent\n0. Exit\nYour choice: ";
        cin >> choice;
    }
    cout << "Good bye" << endl;
    return 0;
}