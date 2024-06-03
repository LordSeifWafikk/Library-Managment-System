#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <iostream>
#include <string>
#include "user.h"
using namespace std;

class admin:public user{
private:
    user userInfo;
    string username;
    string password;
public:
    admin():userInfo(user()),username(""),password(""){};
    admin(string name__,string name,string pass):userInfo(user(name__)),username(name),password(pass){}
    string getUsername();
    string getPassword();
    int getAdminID();
    void displayNameID();
    void operator=(const admin&);

};
#endif // ADMIN_H_INCLUDED
