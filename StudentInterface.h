#ifndef STUDENTINTERFACE_H
#define STUDENTINTERFACE_H
#include "Department.h"
#include "Cart.h"

class StudentInterface {
private:
    Cart shoppingCart;
    Department* departments;
    int totalDepartments;

public:
    StudentInterface(Department* depts, int totalDepts);
    void mainMenu();
    void browseDepartments();
};

#endif