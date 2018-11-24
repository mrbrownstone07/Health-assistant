#ifndef PATIENT_TYPE_DATABASE_H_INCLUDED
#define PATIENT_TYPE_DATABASE_H_INCLUDED
//#include "hashmap.cpp"
#include "patient_type_account.cpp"
#include <string>

class Patient_type_database{
    private:
        hashmap<Patient_type_account> accountMap;//email id, password to account

    public:

        void add(Patient_type_account, bool);
        bool searchUser(string, string, Patient_type_account&);
        void remove(string, string);
        void loadFromFile();


};


#endif // PATIENT_TYPE_DATABASE_H_INCLUDED
