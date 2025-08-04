#include "AdminInterface.h"
#include <iostream>
#include <fstream>
using namespace std;

AdminInterface::AdminInterface(Department*& departments, int& totalDepartments)
    : departments(departments), totalDepartments(totalDepartments) {}
AdminInterface::AdminInterface() : departments(nullptr), totalDepartments(0) {}
AdminInterface::~AdminInterface() {
}


void AdminInterface::listDepartments() const {
    for (int i = 0; i < totalDepartments; ++i) {
        cout << i + 1 << ". " << departments[i].getDepartmentName() << endl;
    }
}

void AdminInterface::addDepartment() {
    cout << "Enter department name: ";
    string name;
    cin.ignore();
    getline(cin, name);

    Department* newDepartments = new Department[totalDepartments + 1];
    for (int i = 0; i < totalDepartments; ++i) {
        newDepartments[i] = departments[i];
    }
    newDepartments[totalDepartments] = Department(name);
    delete[] departments;
    departments = newDepartments;
    totalDepartments++;

    cout << "Department added successfully." << endl;
}

void AdminInterface::addCourseToDepartment() {
    listDepartments();
    cout << "Enter department number [0 to go back]: ";
    int deptIndex;
    cin >> deptIndex;
    if (deptIndex == 0 || deptIndex > totalDepartments) return;

    string number, name, schedule;
    double price;

    cout << "Enter course number: ";
    cin >> number;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter course schedule (M/W, T/R, W/F): ";
    cin >> schedule;
    cout << "Enter course price: ";
    cin >> price;

    Course newCourse(number, name, schedule, price);
    departments[deptIndex - 1].addCourse(newCourse);

    cout << "Course added successfully." << endl;
}

void AdminInterface::saveToCSV(const char* filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cout << "Error saving file." << endl;
        return;
    }
    file << totalDepartments << endl;
    for (int i = 0; i < totalDepartments; ++i) {
        Department& dept = departments[i];
        file << dept.getDepartmentName() << "," << dept.getTotalCourses() << endl;

        for (int j = 0; j < dept.getTotalCourses(); ++j) {
            Course course = dept.getCourse(j);
            file << course.getCourseName() << ","
                 << course.getSchedule() << ","
                 << course.getPrice() << endl;
        }
    }

    file.close();
    cout << "Changes saved successfully." << endl;
}