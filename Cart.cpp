#include "Cart.h"
#include <iostream>
#include <iomanip>
using namespace std;

Cart::Cart() : cartCourses(nullptr), cartSchedules(nullptr), totalCourses(0), totalCost(0.0) {}
Cart::~Cart() {
    delete[] cartCourses;
    delete[] cartSchedules;
}
// Malika leave comments on each function for git commits
void Cart::addCourseToCart(const Course& course, const std::string& schedule) {
    // Dynamically allocate a new array for courses and schedules
    Course* newCartCourses = new Course[totalCourses + 1];
    std::string* newCartSchedules = new std::string[totalCourses + 1];
    
    for (int i = 0; i < totalCourses; ++i) {
        newCartCourses[i] = cartCourses[i];
        newCartSchedules[i] = cartSchedules[i];
    }

    // Adding the new course and schedule
    newCartCourses[totalCourses] = course;
    newCartSchedules[totalCourses] = schedule;

    // Cleaning up old memory
    delete[] cartCourses;
    delete[] cartSchedules;

    // Assigning new memory
    cartCourses = newCartCourses;
    cartSchedules = newCartSchedules;
    totalCost += course.getPrice();
    totalCourses++;

    cout << "Course added to cart successfully." << endl;
}

void Cart::displayCart() const {
    if (totalCourses == 0) {
        cout << "Your cart is empty." << endl;
        return;
    }

    cout << "Courses in your cart:" << endl;
    for (int i = 0; i < totalCourses; ++i) {
        cout << i + 1 << ". ";
        cartCourses[i].displayCourse();
        cout << "Schedule: " << cartSchedules[i] << endl;
    }

    cout << fixed << setprecision(2);
    cout << "Total Cost (including 13% tax): $" << totalCost * 1.13 << endl;
}

void Cart::checkout() {
    if (totalCourses == 0) {
        cout << "No courses in the cart to checkout." << endl;
        return;
    }

    cout << "Thank you for your purchase!" << endl;
    cout << "Total Amount Paid: $" << totalCost * 1.13 << endl;

    // Clear the cart
    delete[] cartCourses;
    delete[] cartSchedules;
    cartCourses = nullptr;
    cartSchedules = nullptr;
    totalCourses = 0;
    totalCost = 0.0;
}

bool Cart::isEmpty() const {
    return totalCourses == 0;
}
