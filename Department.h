#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Course.h"
#include <string>

class Department {
private:
    std::string departmentName;
    Course* courses;
    int totalCourses;

public:
    Department(std::string name = "");
    ~Department();
    void addCourse(const Course& course);
    void displayCourses() const;
    std::string getDepartmentName() const;
    int getTotalCourses() const;
};

#endif
