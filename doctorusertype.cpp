#include "doctorusertype.h"

void Doctor_user_type::setId(string i){
    doctor_id = i;
}

void Doctor_user_type::setRegistrationNumber(string reg){
    doctor_registration_number = reg;
}

void Doctor_user_type::setSpeciality(string spe){
    speciality = spe;
}

string Doctor_user_type::getSpeciality(){
    return speciality;
}

string Doctor_user_type::getId(){
    return doctor_id;
}

string Doctor_user_type::getRegistrationNumber(){
    return doctor_registration_number;
}

string Doctor_user_type::toString(){
    return doctor_id+"\n"+doctor_registration_number+"\n"+speciality+"\n"+
            User_type::toString();
}

