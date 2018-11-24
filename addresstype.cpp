#include "addresstype.h"


AddressType::AddressType(){
    city = nullStr;
    divison = nullStr;
    postal_code = nullStr;
    road_no = nullStr;
    area = nullStr;
}

void AddressType::City(string c){
    city = c;
}

void AddressType::Divison(string d) {
    divison = d;
}

void AddressType::Postal_code(string p){
    postal_code = p;
}

void AddressType::Road_no(string r){
    road_no = r;
}

void AddressType::Area(string a){
    area = a;
}

string AddressType::toString(){
    return road_no+"\n"+area+"\n"+city+"\n"+divison+"\n"+postal_code+"\n";
}

string AddressType::get_Area(){
    return area;
}

string AddressType::get_City(){
    return city;
}

string AddressType::get_Dvision(){
    return divison;
}

string AddressType::get_postal_code(){
    return postal_code;
}

string AddressType::get_Road_no(){
    return road_no;
}

