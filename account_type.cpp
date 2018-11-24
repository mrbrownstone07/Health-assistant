#pragma once
#include "account_type.h"

Account_type::Account_type(){
    account_number = "\0";
    account_password = "\0";
}

void Account_type::set_account_number(string n){
    account_number = n;
}

void Account_type::set_password(string p){
    account_password = p;
}

string Account_type::get_account_number(){
    return account_number;
}

string Account_type::get_password(){
    return account_password;
}

string Account_type::toString(){
    return account_number+"\n"+account_password+"\n";
}

