#ifndef DOCTOR_TYPE_DATABASE_H_INCLUDED
#define DOCTOR_TYPE_DATABASE_H_INCLUDED
#include "hashmap.cpp"
#include "multimap.cpp"
#include <string>
#include "doctor_type_account.cpp"

class doctor_type_database{
    private:
        string Null = "\0";
        hashmap<Doctor_type_account> accountMap; // id to account
        multimap<string> nameMap;   // name to id
        multimap<string> areaMap;   // area to id
        multimap<string> specialityMap; // city to id
        hashmap<string> logInMap;// password, email id to ID

    public:
        void add(Doctor_type_account, bool);
        bool searchByName(string, Doctor_type_account*);
        bool searchByArea(string, Doctor_type_account*);
        bool searchById(string, Doctor_type_account&);
        bool searchBySpeciality(string, Doctor_type_account*);
        int  idAtKeyOnNameMap(string);
        int  idAtKeyOnCityMap(string);
        void removeAccount(string);
        void loadFromFile();
        bool searchUser(string,string, Doctor_type_account&);

};


#endif // DOCTOR_TYPE_DATABASE_H_INCLUDED
