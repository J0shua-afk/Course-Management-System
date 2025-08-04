#ifndef CART_H
#define CART_H
#include "Course.h"

class Cart {
private:
    Course* cartCourses;
    std::string* cartSchedules;
    int totalCourses;
    double totalCost;

public:
    Cart();
    ~Cart();
    void addCourseToCart(const Course& course, const std::string& schedule);
    void displayCart() const;
    void checkout();
    bool isEmpty() const;
};

#endif