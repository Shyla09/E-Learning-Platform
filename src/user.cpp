#include "../include/user.h"

User::User(string n, string u, string p)
    : name(std::move(n)), username(std::move(u)), password(std::move(p)) {}

string User::get_username() const { return username; }
string User::get_password() const { return password; }
string User::get_name() const { return name; }

void User::dashboard() {
    // Base version - does nothing
}