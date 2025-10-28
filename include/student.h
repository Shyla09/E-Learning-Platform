#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "course.h"
#include <vector>
#include <string>
using namespace std;

class Student : public User {
private:
    vector<string> registered_courses;

public:
    Student(string n = "", string u = "", string p = "");

    void register_course(const string &course_code);
    void take_quiz(vector<Course> &courses);
    void submit_assignment(vector<Course> &courses);
    void watch_lecture(vector<Course> &courses);
    void show_dashboard();  // Wrapper for the student dashboard
};

#endif
