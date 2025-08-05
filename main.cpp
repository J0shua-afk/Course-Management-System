#include <iostream>
#include <fstream>
#include "AdminInterface.h"
#include "StudentInterface.h"
#include "Department.h"
#include "Course.h"
using namespace std;


Department* StoreDepartments = nullptr;
int TotalDepartments = 0;
const char* csvFile = "CourseManagementData.csv";


void loadFromCSV(const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "No existing data found. Starting fresh." << endl;
        return;
    }

    file >> TotalDepartments;
    file.ignore();

    StoreDepartments = new Department[TotalDepartments];
    for (int i = 0; i < TotalDepartments; ++i) {
        string departmentName;
        int totalCourses;

        getline(file, departmentName, ',');
        file >> totalCourses;
        file.ignore();

        StoreDepartments[i] = Department(departmentName);

        for (int j = 0; j < totalCourses; ++j) {
            string courseName, schedule;
            double price;

            getline(file, courseName, ',');
            getline(file, schedule, ',');
            file >> price;
            file.ignore();

            Course course("", courseName, schedule, price);
            StoreDepartments[i].addCourse(course);
        }
    }

    file.close();
    cout << "Data loaded successfully from CSV file." << endl;
}

int main() {
    loadFromCSV(csvFile);

    int choice;
    do {
        cout << "\nWelcome to the Course Management System" << endl;
        cout << "1. Student" << endl;
        cout << "2. Admin" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        if (choice == 1) {
            StudentInterface studentInterface(StoreDepartments, TotalDepartments);
            studentInterface.mainMenu();
        } else if (choice == 2) {
            AdminInterface adminInterface(StoreDepartments, TotalDepartments);

            int adminChoice;
            do {
                cout << "\nAdmin Menu" << endl;
                cout << "1. List Departments" << endl;
                cout << "2. Add Department" << endl;
                cout << "3. Add Course to Department" << endl;
                cout << "4. Save Changes to CSV" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice [1-5]: ";
                cin >> adminChoice;

                switch (adminChoice) {
                    case 1: adminInterface.listDepartments(); break;
                    case 2: adminInterface.addDepartment(); break;
                    case 3: adminInterface.addCourseToDepartment(); break;
                    case 4: adminInterface.saveToCSV(csvFile); break;
                    case 5: cout << "Returning to the main menu." << endl; break;
                    default: cout << "Invalid choice. Please try again." << endl;
                }
            } while (adminChoice != 5);
        } else if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    if (StoreDepartments != nullptr) {
        delete[] StoreDepartments;
    }
    return 0;
}
