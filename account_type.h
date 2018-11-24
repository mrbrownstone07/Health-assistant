#pragma once
#ifndef ACCOUNT_TYPE_H_INCLUDED
#define ACCOUNT_TYPE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Account_type{
    private:
        string account_number;
        string account_password;

    public:
        Account_type();

        void set_password(string);
        void set_account_number(string);

        string get_password();
        string get_account_number();

        string toString();
};

#endif // ACCOUNT_TYPE_H_INCLUDED
