#include "doctor_type_database.h"
#include <fstream>
#include <sstream>

void saveToFile(Doctor_type_account& userAccount){
    ofstream MainFile, subFile;
    MainFile.open("doctorMain.txt", std::ofstream::out | std::ofstream::app);

    if(MainFile.is_open()){
        Doctor_user_type user;
        userAccount.getUser(user);
        MainFile << user.getId() << endl;

        subFile.open(user.getId()+".txt");
        if(subFile.is_open()){
            subFile << userAccount.toString();
        }

        subFile.close();
        MainFile.close();

        cout << "Account Saved!" << endl;
    }
}


void doctor_type_database::add(Doctor_type_account newEntry, bool saveInFile){
    Doctor_user_type newUser;
    newEntry.getUser(newUser);

    //if(!saveInFile) newEntry.LoadPatientList();

    accountMap.put(newUser.getRegistrationNumber(), newEntry);
    nameMap.put(newUser.getName().get_name(), newUser.getRegistrationNumber());
    areaMap.put(newUser.getAddress().get_Area(), newUser.getRegistrationNumber());
    specialityMap.put(newUser.getSpeciality(), newUser.getRegistrationNumber());

    string key = newEntry.get_password()+""+newEntry.get_account_number();
    string value  = newUser.getRegistrationNumber();

    logInMap.put(key , value);


    if(saveInFile) saveToFile(newEntry);
}

int doctor_type_database::idAtKeyOnCityMap(string cityName){
    return areaMap.numberOfNodesAtKey(cityName);
}

int doctor_type_database::idAtKeyOnNameMap(string name){
    return nameMap.numberOfNodesAtKey(name);
}

bool doctor_type_database::searchByName(string name, Doctor_type_account* arr){
    int numberOfnames = nameMap.numberOfNodesAtKey(name);
    if(numberOfnames > 0){
        string id[numberOfnames];
        nameMap.find(name,id);

        Doctor_type_account temp;
        for(int i = 0; i<numberOfnames; i++){
            accountMap.find(id[i], temp);
            arr[i] = temp;
        }
        return true;
    }

    return false;
}

bool doctor_type_database::searchByArea(string area, Doctor_type_account* arr){
    int numberOfId = areaMap.numberOfNodesAtKey(area);

    if(numberOfId > 0){
        string id[numberOfId];
        areaMap.find(area, id);

        Doctor_type_account temp;
        for(int i = 0; i<numberOfId; i++){
            accountMap.find(id[i], temp);
            arr[i] = temp;
        }
        return true;
    }

    return false;
}

bool doctor_type_database::searchById(string id, Doctor_type_account& user){
    return accountMap.find(id, user);
}

void doctor_type_database::removeAccount(string id){
    Doctor_type_account Account;
    Doctor_user_type userToBeRemoved;

    accountMap.remove(id, Account);
    Account.getUser(userToBeRemoved);

    string name = userToBeRemoved.getName().get_name();
    string reg = userToBeRemoved.getRegistrationNumber();
    string key = Account.get_password()+""+Account.get_account_number();
    nameMap.remove(name, reg);

    areaMap.remove(userToBeRemoved.getAddress().get_Area(), reg);
    specialityMap.remove(userToBeRemoved.getSpeciality(), reg);

    logInMap.remove(key, reg);
}

void doctor_type_database::loadFromFile(){

    string fName, Mname, Lname, area, city, division, postalCode, roadNo,
            sex, id, regNo, eMail, passWord, speciality, d, m, y, Age, name;
    int age;

    ifstream MainFile, subFile;
    MainFile.open("doctorMain.txt");
    int coun = 0;
    if(MainFile.is_open()){

        do{
            getline(MainFile, id);
            if(id == "\0") break;

            subFile.open(id+".txt");
            if(subFile.is_open()){

                getline(subFile, id);
                getline(subFile, regNo);
                getline(subFile, speciality);
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
                cout << "could not open!" << endl;
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

            Doctor_user_type u;
            u.setName(name);
            u.setAddress(add);
            u.setBirthDate(date);
            u.setSex(sex);
            u.setAge(age);
            u.setId(id);
            u.setRegistrationNumber(regNo);
            u.setEmail(eMail);
            u.setSpeciality(speciality);

            Doctor_type_account newAccount;
            newAccount.set_account_number(eMail);
            newAccount.set_password(passWord);
            newAccount.setUser(u);

            doctor_type_database::add(newAccount, false);

        }while(id != Null);

        MainFile.close();

    }

}

bool doctor_type_database::searchUser(string pass, string email, Doctor_type_account& UserAcc){
    string key = pass+""+email;
    string id;

    bool found = logInMap.find(key, id);

    if(found) return accountMap.find(id, UserAcc);
    else return false;
}





































































































































