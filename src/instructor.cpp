#include "instructor.h"
#include "utils.h"
#include <iostream>
using namespace std;

extern vector<Course> all_courses;

Instructor::Instructor(string n, string u, string p) : User(n, u, p) {}

void Instructor::create_course() {
    string code, name, link;
    cout << "Enter course code: ";
    getline(cin, code);
    cout << "Enter course name: ";
    getline(cin, name);
    cout << "Enter lecture video link: ";
    getline(cin, link);

    all_courses.push_back(Course(code, name, get_name(), link));
    cout << "Course created successfully!\n";
}

void Instructor::add_assignment() {
    if (all_courses.empty()) {
        cout << "No courses available!\n";
        return;
    }
    cout << "Enter course code: ";
    string code;
    getline(cin, code);

    for (auto &c : all_courses) {
        if (c.get_code() == code) {
            cout << "Enter assignment description: ";
            string a;
            getline(cin, a);
            c.add_assignment(a);
            cout << "Assignment added!\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

void Instructor::add_quiz() {
    cout << "Enter course code: ";
    string code;
    getline(cin, code);

    for (auto &c : all_courses) {
        if (c.get_code() == code) {
            string title;
            cout << "Enter quiz title: ";
            getline(cin, title);
            Quiz quiz(title);

            int num;
            cout << "Enter number of questions: ";
            cin >> num;
            cin.ignore();

            for (int i = 0; i < num; ++i) {
                string text;
                vector<string> opts(4);
                int correct;

                cout << "\nQuestion " << i + 1 << " text: ";
                getline(cin, text);

                for (int j = 0; j < 4; ++j) {
                    cout << "Option " << j + 1 << ": ";
                    getline(cin, opts[j]);
                }
                cout << "Enter correct option number (1-4): ";
                cin >> correct;
                cin.ignore();

                quiz.add_question(Question(text, opts, correct));
            }

            c.add_quiz(quiz);
            cout << "Quiz added successfully!\n";
            return;
        }
    }
    cout << "Course not found!\n";
}

void Instructor::show_dashboard() {
    int choice;
    do {
        cout << "\n--- Instructor Dashboard (" << get_name() << ") ---\n";
        cout << "1. Create Course\n";
        cout << "2. Add Assignment\n";
        cout << "3. Add Quiz\n";
        cout << "4. Logout\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: create_course(); break;
            case 2: add_assignment(); break;
            case 3: add_quiz(); break;
            case 4: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
}
