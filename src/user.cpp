#include "../include/user.h"

User::User(std::string n, std::string u, std::string p)
    : name(std::move(n)), username(std::move(u)), password(std::move(p)) {}

std::string User::get_username() const { return username; }
std::string User::get_password() const { return password; }
std::string User::get_name() const { return name; }
