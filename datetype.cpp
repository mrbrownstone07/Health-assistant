#include "datetype.h"
#include <string>

DateType::DateType(){
    day = Null;
    month = Null;
    year = Null;
}

void DateType::Day(string d){
    day = d;
}

void DateType::Month(string m){
    month = m;
}

void DateType::Year(string y){
    year = y;
}

string DateType::get_day(){
    return day;
}

string DateType::get_month(){
    return month;
}

string DateType::get_year(){
    return year;
}

RelationType DateType::compare_To(DateType otherDate){
    return Equal;
}

string DateType::toString(){
    return day+"\n"+month+"\n"+year+"\n";
}

