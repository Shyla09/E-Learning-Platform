#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "user.h"
#include "course.h"
#include "quiz.h"
#include <vector>
#include <string>
using namespace std;

class Instructor : public User {
public:
    Instructor(string n = "", string u = "", string p = "");
    void create_course();
    void add_assignment();
    void add_quiz();
    void show_dashboard();
};

#endif
