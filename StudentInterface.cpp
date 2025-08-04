#include "StudentInterface.h"
#include <iostream>
using namespace std;

StudentInterface::StudentInterface(Department* depts, int totalDepts) 
    : departments(depts), totalDepartments(totalDepts) {}

void StudentInterface::mainMenu() {
    int choice;

    do {
        cout << "\nStudent Main Menu" << endl;
        cout << "1. Show Cart" << endl;
        cout << "2. Browse Departments" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shoppingCart.displayCart();
            break;
        case 2:
            browseDepartments();
            break;
        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

