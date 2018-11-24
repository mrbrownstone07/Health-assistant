#include "patient_type_database.h"
#include <fstream>

void saveToFile(Patient_type_account& userAcc){
    ofstream MainFile, subFile;
    MainFile.open("patientMain.txt", std::ofstream::out | std::ofstream::app);

    if(MainFile.is_open()){
        Patient_user_type user;
        userAcc.getUser(user);
        MainFile << user.getId() << endl;

        subFile.open(user.getId()+".txt");
        if(subFile.is_open()){
            subFile << userAcc.toString();
        }
        subFile.close();
        MainFile.close();
        cout << "Account Saved!" << endl;
    }
}


void Patient_type_database::add(Patient_type_account newAccount, bool save){
    Patient_user_type newUser;
    newAccount.getUser(newUser);

    string key = newAccount.get_account_number()+""+
                    newAccount.get_password();
    accountMap.put(key, newAccount);

    if(save) saveToFile(newAccount);
}


bool Patient_type_database::searchUser(string email, string pass, Patient_type_account& UserAcc){
    string key = email+pass;
    cout << key << endl;
    return accountMap.find(key, UserAcc);
}

void Patient_type_database::remove(string email, string pass){
    string key = email+pass;
    Patient_type_account accountTobeRemoved;
    accountMap.remove(key, accountTobeRemoved);
}


void Patient_type_database::loadFromFile(){

    string fName, Mname, Lname, area, city, division, postalCode, roadNo,
            sex, id, eMail, passWord, d, m, y, Age;
    int age;

    ifstream MainFile, subFile;
    MainFile.open("patientMain.txt");

    if(MainFile.is_open()){

        do{
            getline(MainFile, id);
            if(id == "\0") break;

            subFile.open(id+".txt");
            if(subFile.is_open()){

                getline(subFile, id);
                getline(subFile, fName);
                getline(subFile, Mname);
                getline(subFile, Lname);
                getline(subFile, Age);
                getline(subFile, sex);
                getline(subFile, d);
                getline(subFile, m);
                getline(subFile, y);
                getline(subFile, roadNo);
                getline(subFile, area);
                getline(subFile, city);
                getline(subFile, division);
                getline(subFile, postalCode);
                getline(subFile, eMail);
                getline(subFile, passWord);

                subFile.close();
                age = stoi(Age);
            }else{
                cout << "File not Found!" << endl;
            }

            NameType name;
            name.First_name(fName);
            name.Mid_name(Mname);
            name.Last_name(Lname);

            DateType date;
            date.Day(d);
            date.Month(m);
            date.Year(y);

            AddressType add;
            add.Area(area);
            add.City(city);
            add.Divison(division);
            add.Postal_code(postalCode);
            add.Road_no(roadNo);

            Patient_user_type u;
            u.setName(name);
            u.setAddress(add);
            u.setBirthDate(date);
            u.setSex(sex);
            u.setAge(age);
            u.setId(id);
            u.setEmail(eMail);

            Patient_type_account newAccount;
            newAccount.set_account_number(eMail);
            newAccount.set_password(passWord);
            newAccount.setUser(u);

            Patient_type_database::add(newAccount, false);
        }while(id != "\0");

        MainFile.close();
    }

}
























