#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <vector>
#include "question.h"
using namespace std;

class Quiz {
private:
    string title;
    vector<Question> questions;

public:
    Quiz(string t = "");

    void add_question(const Question &q);
    void start() const;

    string get_title() const;
    int get_question_count() const;
};

#endif
