#ifndef UTILS_H
#define UTILS_H

#include "student.h"
#include "instructor.h"
#include "course.h"
#include <vector>
#include <string>
using namespace std;

extern vector<Course> all_courses;

void initialize_data();
void signup_student();
void signup_instructor();
void login_user();

#endif
