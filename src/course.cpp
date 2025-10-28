#include "course.h"
#include <iostream>
using namespace std;

Course::Course(string c, string n, string i, string l)
    : code(c), name(n), instructor(i), lecture_link(l) {}

string Course::get_code() const { return code; }
string Course::get_name() const { return name; }
string Course::get_instructor() const { return instructor; }
string Course::get_lecture_link() const { return lecture_link; }

void Course::add_assignment(const string &assignment) {
    assignments.push_back(assignment);
}

void Course::add_quiz(const Quiz &quiz) {
    quizzes.push_back(quiz);
}

int Course::get_assignment_count() const {
    return assignments.size();
}

int Course::get_quiz_count() const {
    return quizzes.size();
}

void Course::list_assignments() const {
    for (size_t i = 0; i < assignments.size(); ++i)
        cout << i + 1 << ". " << assignments[i] << endl;
}

void Course::start_quiz() const {
    if (quizzes.empty()) {
        cout << "No quizzes available for this course.\n";
        return;
    }

    const Quiz &quiz = quizzes[0]; // assuming one quiz per course for simplicity
    quiz.start();
}
