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

    string get_name() const;
    string get_username() const;
    string get_password() const;

    // Non-pure virtual so derived classes can optionally override
    virtual void dashboard();
};

#endif
