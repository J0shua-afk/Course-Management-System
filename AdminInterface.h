#ifndef ADMININTERFACE_H
#define ADMININTERFACE_H

#include "Department.h"

class AdminInterface {
private:
    Department* departments;
    int totalDepartments;

public:
    AdminInterface();
    ~AdminInterface();
    void listDepartments() const;
    void addDepartment();
    void addCourseToDepartment();
    void saveToCSV(const char* filePath);
};

#endif
