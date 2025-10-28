# E-Learning-Platform
#  E-Learning Platform (C++ OOP Project)

A console-based **E-Learning System** built in **C++**, demonstrating the use of **Object-Oriented Programming** concepts such as *inheritance, polymorphism, encapsulation, and file handling*.  
Students can register, take quizzes, submit assignments, and track progress — while instructors can create courses, manage quizzes, and grade submissions.

---

##  Features

###  Student Module
- Register and log in as a student
- View and enroll in available courses
- Access video lectures for each course
- View and submit assignments
- Take quizzes with automatic scoring
- View grades and quiz performance history

###  Instructor Module
- Register and log in as an instructor
- Create new courses
- Add assignments and quizzes to courses
- View student submissions
- Grade and provide feedback
- Track class performance

---

##  Concepts Demonstrated
- **Classes & Objects**
- **Inheritance** (User → Student / Instructor)
- **Polymorphism** (`dashboard()` function)
- **File Handling** (persistent storage of users, grades, and submissions)
- **Encapsulation** (private data members and getters)
- **Data Structures** (vectors for dynamic lists)

---

## 📂 Project Structure

```text
📂 E-Learning-Platform
 ┣ 📂 include/             # Header files (.h)
  ┣ 📜 course.h
  ┣ 📜 instructor.h
  ┣ 📜 question.h
  ┣ 📜 quiz.h
  ┣ 📜 student.h
  ┣ 📜 user.h
  ┗ 📜 utils.h
 ┣ 📂 src/                 # Source files (.cpp)
  ┣ 📜 main.cpp
  ┣ 📜 course.cpp
  ┣ 📜 instructor.cpp
  ┣ 📜 question.cpp
  ┣ 📜 quiz.cpp
  ┣ 📜 student.cpp
  ┗ 📜 user.cpp
 ┣ 📂 data/                # Runtime data files
  ┣ 📜 students.dat
  ┣ 📜 instructors.dat
  ┣ 📜 submissions.dat
  ┣ 📜 grades.dat
  ┗ 📜 scores.dat
 ┣ 📜 README.md            # Documentation
 ┣ 📜 Makefile             # Build instructions


