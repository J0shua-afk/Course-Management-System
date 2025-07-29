#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course {
private:
    std::string courseNumber;
    std::string courseName;
    std::string schedule;
    double price;

public:
    Course(std::string num = "", std::string name = "", std::string sched = "", double cost = 0.0);
    std::string getCourseNumber() const;
    std::string getCourseName() const;
    std::string getSchedule() const;
    double getPrice() const;
    void displayCourse() const;
};

#endif
