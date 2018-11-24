#include "nametype.h"

NameType::NameType(){
    fname = nullStr;
    lname = nullStr;
    mname = nullStr;
}

void NameType::First_name(string f){
    fname = f;
}

void NameType::Last_name(string l){
    lname = l;
}

void NameType::Mid_name(string m){
    mname = m;
}

string NameType::toString(){
    if(mname != nullStr && fname != nullStr && lname != nullStr)
        return fname+"\n"+mname+"\n"+lname+"\n";
    if(mname == nullStr && fname != nullStr && lname != nullStr)
        return fname+"\n"+lname+"\n";
}

string NameType::get_first_name(){
    return fname;
}

string NameType::get_last_name(){
    return lname;
}

string NameType::get_mid_name(){
    return mname;
}

string NameType::get_name(){
    if(mname != nullStr && fname != nullStr && lname != nullStr)
        return fname+" "+mname+" "+lname;
    if(mname == nullStr && fname != nullStr && lname != nullStr)
        return fname+" "+lname;
}
