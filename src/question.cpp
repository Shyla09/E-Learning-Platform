#include "question.h"

Question::Question(string t, vector<string> o, int c)
    : text(t), options(o), correct_option(c) {}

string Question::get_text() const { return text; }
vector<string> Question::get_options() const { return options; }
int Question::get_correct_option() const { return correct_option; }
