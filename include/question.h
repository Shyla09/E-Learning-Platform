#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string text;
    vector<string> options;
    int correct_option;

public:
    Question(string t = "", vector<string> o = {}, int c = 1);

    string get_text() const;
    vector<string> get_options() const;
    int get_correct_option() const;
};

#endif
