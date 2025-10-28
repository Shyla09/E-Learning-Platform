#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string name;
    string username;
    string password;

public:
    User(string n = "", string u = "", string p = "");
    virtual ~User() {}

    string get_name() const { return name; }
    string get_username() const { return username; }
    string get_password() const { return password; }

    // make this NON-pure so derived classes are not forced to override
    virtual void dashboard() {}
};

#endif
