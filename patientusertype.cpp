#include "patientusertype.h"

void Patient_user_type::setId(string i){
    patient_id = i;
}

string Patient_user_type::getId(){
    return patient_id;
}

string Patient_user_type::toString(){
    return patient_id+"\n"+User_type::toString()+"";
}

