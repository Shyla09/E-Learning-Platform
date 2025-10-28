#include "student.h"
#include "course.h"
#include "quiz.h"
#include "utils.h"
#include <iostream>
using namespace std;

extern vector<Course> all_courses;

// Constructor
Student::Student(string n, string u, string p) : User(n, u, p) {}

// Register for a course
void Student::register_course(const string &course_code) {
    for (const auto &c : all_courses) {
        if (c.get_code() == course_code) {
            // Prevent duplicate registration
            for (const auto &reg : registered_courses) {
                if (reg == course_code) {
                    cout << "You are already registered for " << c.get_name() << "!\n";
                    return;
                }
            }
            registered_courses.push_back(course_code);
            cout << "Successfully registered for " << c.get_name() << "!\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

// Take quiz
void Student::take_quiz(vector<Course> &courses) {
    cout << "Enter course code to take quiz: ";
    string code;
    getline(cin, code);

    for (auto &c : courses) {
        if (c.get_code() == code) {
            if (c.get_quiz_count() == 0) {
                cout << "No quizzes available for this course.\n";
                return;
            }
            c.start_quiz();
            return;
        }
    }
    cout << "Course not found!\n";
}

// Submit assignment
void Student::submit_assignment(vector<Course> &courses) {
    cout << "Enter course code to submit assignment: ";
    string code;
    getline(cin, code);

    for (auto &c : courses) {
        if (c.get_code() == code) {
            if (c.get_assignment_count() == 0) {
                cout << "No assignments for this course.\n";
                return;
            }
            cout << "Assignments for " << c.get_name() << ":\n";
            c.list_assignments();
            cout << "Enter assignment number to submit: ";
            int num;
            cin >> num;
            cin.ignore();
            if (num < 1 || num > c.get_assignment_count()) {
                cout << "Invalid assignment number.\n";
                return;
            }
            cout << "Submission successful!\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

// Watch lecture
void Student::watch_lecture(vector<Course> &courses) {
    cout << "Enter course code to watch lecture: ";
    string code;
    getline(cin, code);

    for (auto &c : courses) {
        if (c.get_code() == code) {
            cout << "Watch lecture here: " << c.get_lecture_link() << "\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

// Show student dashboard (menu loop)
void Student::show_dashboard() {
    int choice;
    do {
        cout << "\n--- Student Dashboard (" << get_name() << ") ---\n";
        cout << "1. View Courses\n";
        cout << "2. Register for Course\n";
        cout << "3. Take Quiz\n";
        cout << "4. Submit Assignment\n";
        cout << "5. Watch Lecture Video\n";
        cout << "6. Logout\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                for (const auto &c : all_courses) {
                    cout << "[" << c.get_code() << "] " << c.get_name()
                         << "\nInstructor: " << c.get_instructor()
                         << "\nAssignments: " << c.get_assignment_count()
                         << " | Quizzes: " << c.get_quiz_count() << "\n\n";
                }
                break;
            }
            case 2: {
                cout << "Available courses:\n";
                for (const auto &c : all_courses) {
                    cout << "- " << c.get_code() << ": " << c.get_name() << endl;
                }
                cout << "Enter course code to register: ";
                string code;
                getline(cin, code);
                register_course(code);
                break;
            }
            case 3:
                take_quiz(all_courses);
                break;
            case 4:
                submit_assignment(all_courses);
                break;
            case 5:
                watch_lecture(all_courses);
                break;
            case 6:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}
