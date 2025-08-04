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
void StudentInterface::browseDepartments() {
    if (totalDepartments == 0) {
        cout << "No departments available to browse." << endl;
        return;
    }

    int deptChoice;
    do {
        cout << "\nAvailable Departments:" << endl;
        for (int i = 0; i < totalDepartments; ++i) {
            cout << i + 1 << ". " << departments[i].getDepartmentName() << endl;
        }
        cout << "0. Go Back to Main Menu" << endl;
        cout << "Enter department number [0 to go back]: ";
        cin >> deptChoice;

        if (deptChoice > 0 && deptChoice <= totalDepartments) {
            int courseChoice;
            do {
                cout << "\nCourses in Department: " << departments[deptChoice - 1].getDepartmentName() << endl;
                departments[deptChoice - 1].displayCourses();
                cout << "0. Go Back" << endl;
                cout << "Enter course number to add to cart [0 to go back]: ";
                cin >> courseChoice;

                if (courseChoice > 0 && courseChoice <= departments[deptChoice - 1].getTotalCourses()) {
                    Course selectedCourse = departments[deptChoice - 1].getCourseNumber(courseChoice - 1);
                    string schedule = selectedCourse.getSchedule();
                    shoppingCart.addCourseToCart(selectedCourse, schedule);
                } else if (courseChoice != 0) {
                    cout << "Invalid course number. Please try again." << endl;
                }
            } while (courseChoice != 0);
        } else if (deptChoice != 0) {
            cout << "Invalid department number. Please try again." << endl;
        }
    } while (deptChoice != 0);
}
