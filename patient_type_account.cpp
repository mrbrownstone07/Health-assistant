#include "patient_type_account.h"

Patient_type_account::Patient_type_account(){

}

void Patient_type_account::setUser(Patient_user_type newUser){
    user = newUser;
}

void Patient_type_account::getUser(Patient_user_type& newUser){
    newUser = user;
}

string Patient_type_account::toString(){
    return user.toString()+Account_type::toString()+"\n";
}

