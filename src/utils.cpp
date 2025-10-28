#include "utils.h"
#include <iostream>
using namespace std;

vector<Course> all_courses;

void initialize_data() {
    all_courses.push_back(Course("CS101", "Programming Fundamentals", "Dr. Khan", "youtube.com/lectures/cs101"));
    all_courses.push_back(Course("CS102", "Data Structures", "Ms. Sharma", "youtube.com/lectures/cs102"));
    all_courses.push_back(Course("CS201", "Algorithms", "Dr. Iyer", "youtube.com/lectures/cs201"));
    all_courses.push_back(Course("CS301", "Operating Systems", "Mr. Nair", "youtube.com/lectures/cs301"));

    all_courses[0].add_assignment("Implement a calculator");
    all_courses[0].add_assignment("Create a simple banking app");

    all_courses[1].add_assignment("Implement linked list");
    all_courses[1].add_assignment("Binary tree traversal");

    Quiz quiz1("Basics Quiz");
    quiz1.add_question(Question("What does CPU stand for?",
                                {"Central Processing Unit", "Computer Personal Unit", "Central Power Unit", "Central Process Utility"}, 1));
    all_courses[0].add_quiz(quiz1);

    Quiz quiz2("DSA Quiz");
    quiz2.add_question(Question("Which data structure uses FIFO?",
                                {"Stack", "Queue", "Tree", "Graph"}, 2));
    all_courses[1].add_quiz(quiz2);
}

void signup_student() {
    string name, username, password;
    cout << "\nStudent Sign Up\n";
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    Student s(name, username, password);
    cout << "Student signup successful!\n";
    s.show_dashboard();
}

void signup_instructor() {
    string name, username, password;
    cout << "\nInstructor Sign Up\n";
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    Instructor i(name, username, password);
    cout << "Instructor signup successful!\n";
    i.show_dashboard();
}

void login_user() {
    int type;
    cout << "\nLogin as: 1.Student 2.Instructor\nEnter choice: ";
    cin >> type;
    cin.ignore();

    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (type == 1) {
        Student s("Temp", username,
