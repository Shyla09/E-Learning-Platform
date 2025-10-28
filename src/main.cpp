#include "../include/utils.h"
#include "../include/user.h"
#include "../include/course.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<Course> all_courses;

// Provide a simple definition so initialize_courses is defined.
// This ensures the program compiles; adjust implementation to actually
// load Course objects if your Course class exposes loading functions.
void initialize_courses() {
    // Ensure the courses data file exists; create a default entry if missing.
    std::ifstream cf("courses.dat");
    if (!cf) {
        std::ofstream of("courses.dat");
        of << "Intro to C++:101\n";
    }
    // If you have code to populate all_courses from the file, call it here.
}

int main() {
    initialize_courses();

    ifstream f("instructors.dat");
    if (!f) {
        ofstream of("instructors.dat");
        of << "Default Instructor:admin:admin\n";
        cout << "Default instructor created (admin/admin)\n";
    }

    int choice;
    do {
        cout << "\n=== E-Learning System ===\n";
        cout << "1. Student Sign Up\n2. Instructor Sign Up\n3. Login\n4. Exit\nEnter choice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cin.ignore();

        switch (choice) {
            case 1: signup_student(); break;
            case 2: signup_instructor(); break;
            case 3: {
                login_user();
                break;
            }
            case 4: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 4);
    return 0;
}
