#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "quiz.h"
using namespace std;

class Course {
private:
    string code;
    string name;
    string instructor;
    string lecture_link;
    vector<string> assignments;
    vector<Quiz> quizzes;

public:
    Course(string c = "", string n = "", string i = "", string l = "");

    string get_code() const;
    string get_name() const;
    string get_instructor() const;
    string get_lecture_link() const;

    void add_assignment(const string &assignment);
    void add_quiz(const Quiz &quiz);

    int get_assignment_count() const;
    int get_quiz_count() const;

    void list_assignments() const;
    void start_quiz() const;
};

#endif
