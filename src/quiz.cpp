#include "quiz.h"
#include <iostream>
using namespace std;

Quiz::Quiz(string t) : title(t) {}

void Quiz::add_question(const Question &q) {
    questions.push_back(q);
}

void Quiz::start() const {
    if (questions.empty()) {
        cout << "No questions available in this quiz.\n";
        return;
    }

    cout << "\n=== Starting Quiz: " << title << " ===\n";
    int score = 0;
    int qnum = 1;

    for (const auto &q : questions) {
        cout << "\nQ" << qnum++ << ": " << q.get_text() << endl;
        const auto &opts = q.get_options();
        for (size_t i = 0; i < opts.size(); ++i) {
            cout << i + 1 << ". " << opts[i] << endl;
        }

        cout << "Your answer (1-" << opts.size() << "): ";
        int ans;
        cin >> ans;
        cin.ignore();

        if (ans == q.get_correct_option()) {
            cout << "✅ Correct!\n";
            score++;
        } else {
            cout << "❌ Wrong. Correct answer: "
                 << q.get_correct_option() << ". "
                 << opts[q.get_correct_option() - 1] << "\n";
        }
    }

    cout << "\nQuiz finished! Your score: " << score << "/" << questions.size() << "\n";
}

string Quiz::get_title() const { return title; }

int Quiz::get_question_count() const { return questions.size(); }
