#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(std::string num, std::string name, std::string sched, double cost)
    : courseNumber(num), courseName(name), schedule(sched), price(cost) {}

std::string Course::getCourseNumber() const { return courseNumber; }
std::string Course::getCourseName() const { return courseName; }
std::string Course::getSchedule() const { return schedule; }
double Course::getPrice() const { return price; }

void Course::displayCourse() const {
    cout << courseNumber << " - " << courseName << " (" << schedule << ") - $" << price << endl;
}
