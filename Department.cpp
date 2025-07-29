#include "Department.h"
#include <iostream>
using namespace std;

Department::Department(std::string name) : departmentName(name), courses(nullptr), totalCourses(0) {}

Department::~Department() {
    delete[] courses;
}

void Department::addCourse(const Course& course) {
    Course* newCourses = new Course[totalCourses + 1];
    for (int i = 0; i < totalCourses; ++i) {
        newCourses[i] = courses[i];
    }
    newCourses[totalCourses] = course;
    delete[] courses;
    courses = newCourses;
    totalCourses++;
}

void Department::displayCourses() const {
    for (int i = 0; i < totalCourses; ++i) {
        cout << i + 1 << ". ";
        courses[i].displayCourse();
    }
}

std::string Department::getDepartmentName() const { return departmentName; }
int Department::getTotalCourses() const { return totalCourses; }
