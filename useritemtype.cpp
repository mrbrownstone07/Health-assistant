#pragma once
#include "useritemtype.h"

User_type::User_type(){
}

void User_type::setName(NameType n){
    name = n;
}

void User_type::setAge(int a){
    age = a;
}

void User_type::setAddress(AddressType a){
    address = a;
}

void User_type::setBirthDate(DateType d){
    birth_date = d;
}

void User_type::setSex(string s){
    sex = s;
}

void User_type::setVoterId(string VI){
    voterId = VI;
}

void User_type::setEmail(string mail){
    emailId = mail;
}

string User_type::toString(){
    string a = to_string(age);
    return name.toString()+""+a+"\n"+sex+"\n"+birth_date.toString()
            +""+address.toString()+"";
}

AddressType User_type::getAddress(){
    return address;
}

NameType User_type::getName(){
    return name;
}

DateType User_type::getBirthDate(){
    return birth_date;
}

string User_type::getSex(){
    return sex;
}

int User_type::getAge(){
    return age;
}

string User_type::getEmail(){
    return emailId;
}

string User_type::getVoterId(){
    return voterId;
}

