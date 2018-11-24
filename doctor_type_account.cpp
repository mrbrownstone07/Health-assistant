#include "doctor_type_account.h"
#include <fstream>

Doctor_type_account::Doctor_type_account(){

}

void Doctor_type_account::setUser(Doctor_user_type newUser){
    user = newUser;
}

void Doctor_type_account::getUser(Doctor_user_type& item){
    item = user;
}

string Doctor_type_account::toString(){
    return user.toString()+""+Account_type::toString()+"\n";
}

void Doctor_type_account::post_review(Review_type newReview){
    new_review_handler.post_review(newReview);
}

void Doctor_type_account::get_review(Review_type& newReview){
    new_review_handler.get_review(newReview);
}

void Doctor_type_account::print_reviews(){
    new_review_handler.print_reviews();
}

int Doctor_type_account::getNumberOfReviews(){
    return new_review_handler.get_number_of_reviews();
}

bool Doctor_type_account::add_patient(string id, bool save){
    bool inList = patient_list.find(id);

    if(!inList){
         patient_list.add(id);
         if(save) Doctor_type_account::SavePatientList();
         return true;
    }
    else{
        return false;
    }


}

void Doctor_type_account::seeNextPatient(){
    string currentAppointment = patient_list.appointmentDone();

    string fName, Mname, Lname, area, city, division, postalCode, roadNo,
            sex, id, eMail, passWord, d, m, y, Age;

    ifstream FILE;
    cout << currentAppointment << endl;
    FILE.open(currentAppointment+".txt");

    if(FILE.is_open()){

        getline(FILE, id);
        getline(FILE, fName);
        getline(FILE, Mname);
        getline(FILE, Lname);
        getline(FILE, Age);
        getline(FILE, sex);
        getline(FILE, d);
        getline(FILE, m);
        getline(FILE, y);
        getline(FILE, roadNo);
        getline(FILE, area);
        getline(FILE, city);
        getline(FILE, division);
        getline(FILE, postalCode);
        getline(FILE, eMail);

        FILE.close();
    }

    cout << "Patient's Information\n" << endl;
    cout << "Voter ID: " << id << endl;
    cout << "Name: " << fName+" "+Mname+" "+Lname << endl;
    cout << "Age: " << Age << endl;
    cout << "Sex: " << sex << endl;
    cout << "Birth Date: " << d+"/"+m+"/"+y << endl;
    cout << "Email ID: " << eMail << endl;
}

void Doctor_type_account::SavePatientList(){

    ofstream FILE;
    cout << "Saving " << user.getId();
    FILE.open(user.getId()+" patient List.txt", std::ofstream::out | std::ofstream::app);

    if(FILE.is_open()){
        FILE << patient_list.toString() << endl;
    }

    FILE.close();
}


void Doctor_type_account::LoadPatientList(){

    ifstream FILE;
    FILE.open(user.getId()+" patient List.txt");


    if(FILE.is_open()){
        string buffer;

        do{
            getline(FILE, buffer);


            if(buffer == "\0"){
                getline(FILE, buffer);
                if(buffer == "\0") break;
            }

            bool inList = patient_list.find(buffer);
            if(!inList) patient_list.add(buffer);

        }while(buffer != "\0");

        FILE.close();
    }else{
        cout << "File could not open" << endl;
    }
}

int Doctor_type_account::NumberOfAppointments(){
    patient_list.getNumberOfPatients();
}

void Doctor_type_account::showAllAppointments(){

    for(int i = 0; i<patient_list.getNumberOfPatients(); i++){
        string id = patient_list.next();
        cout << id << endl;
    }

}




















