#include "manager.h"
#include <unistd.h>
#include <iomanip>
#include <fstream>

Manager::Manager(){

    patientDataBase.loadFromFile();
    doctorDataBase.loadFromFile();
}

void welcomeWindow(){

    cout << "\t\t\t-----Health Assistant-----\n\n" << endl;
}

void exitWindow(){
    welcomeWindow();
    cout << "CSE - 225 Lab Project" << endl;
    cout << "By: Navid Bin Islam and Mahdi Mohammad Shibli" << endl;
    exit(0);
}

void clearConsole(){
    system("clear");
}

void Manager::mainWindow(){
    int opp;

    while(opp != 4){
        welcomeWindow();
        cout << "Main Window>>\n"<<endl;

        cout << "1.Log In" << endl;
        cout << "2.Sign Up" << endl;
        cout << "3.Terms and Condition" << endl;
        cout << "4.Exit" << endl;
        cout <<"\nEnter Your choice: " << endl;

        cin >> opp;

        switch(opp){

            case 1:
                clearConsole();
                logInWindow();
                mainWindow();
                break;

            case 2:
                clearConsole();
                signUpWindow();
                mainWindow();
                break;

            case 3:
                clearConsole();
                //ShowTerms();
                mainWindow();
                break;

            case 4:
                clearConsole();
                exitWindow();
                break;

            default:
                cout << "Wrong Input" << endl;
                break;
        }
    }

}

void Manager::signUpWindow(){
    int opp;

    while(opp != 4){
        welcomeWindow();

        cout << "Sign-up Window>>\n" << endl;

        cout << "1.Are you a doctor?" << endl;
        cout << "2.Are you a patient?" << endl;
        cout << "3.Go Back" << endl;
        cout << "4.Exit" << endl;
        cout <<"\nEnter Your choice: " << endl;

        cin >> opp;
        switch(opp){
            case 1:
                clearConsole();
                doctorSignUp();
                break;
            case 2:
                clearConsole();
                patientSignUp();
                break;
            case 3:
                clearConsole();
                return;
                break;
            case 4:
                clearConsole();
                exitWindow();
                exit(0);

        }
    }
}

void Manager::logInWindow(){
    int opp;

    while(opp != 4){
        welcomeWindow();

        cout << "Log-in Window>>\n" << endl;

        cout << "1.Are you a doctor?" << endl;
        cout << "2.Are you a patient?" << endl;
        cout << "3.Go Back" << endl;
        cout << "4.Exit" << endl;
        cout <<"\nEnter Your choice: ";

        cin >> opp;

        switch(opp){
            case 1:
                clearConsole();
                DoctorLogIn();
                break;
            case 2:
                clearConsole();
                patientLogIn();
                break;
            case 3:
                clearConsole();
                mainWindow();
                break;
            case 4:
                clearConsole();
                exitWindow();
                break;
        }

    }

}

void Manager::PatientLoggedInWindow(Patient_type_account& userAccount){
    clearConsole();
    welcomeWindow();

    Patient_user_type user;
    userAccount.getUser(user);

    clearConsole();
    welcomeWindow();

    cout << "Paitent Profile Window>>\n" << endl;

    cout << "Hello ";
    cout << user.getName().get_first_name() << "," <<endl;

    int opp;
    while(opp != 3){

        cout << "\n1.Search A doctor" << endl;
        cout << "2.See Appointments" << endl;
        cout << "3.Log out" << endl;
        cout <<"\nEnter Your choice: ";

        cin >> opp;
        switch(opp){

            case 1:
                clearConsole();
                searchDoctorWindow(user.getId(), userAccount);
                break;

            case 2:
                break;

            case 3:
                clearConsole();
                mainWindow();
                break;
        }
    }
}

void Manager::patientLogIn(){
    welcomeWindow();
    cout << "Patient Log In window>>\n" << endl;

    string mail, pass;

    cout << "Email: ";
    cin >> mail;
    cout << "Password: ";
    cin >> pass;

    Patient_type_account userAccount;
    bool found = patientDataBase.searchUser(mail, pass, userAccount);

    if(found){
        clearConsole();
        PatientLoggedInWindow(userAccount);
    }
    else{
        clearConsole();
        int o;
        cout << "Log in Failed!\n" << endl;

        cout << "Enter 0 to go back, 1 to try again: ";
        cin >> o;

        if(o == 0){
            clearConsole();
            return;
        }
        if(o == 1){
            clearConsole();
            patientLogIn();
        }
    }
}

void Manager::afterDoctorLogIn(Doctor_type_account& userAccount){
        Doctor_user_type user;
        userAccount.getUser(user);
        userAccount.LoadPatientList();

        clearConsole();
        welcomeWindow();

        cout << "Doctor Account Window>>\n" << endl;
        string buff;
        cout << "\nHello Doctor ";
        cout << user.getName().get_first_name() << endl;

        cout << "Today you Have " << userAccount.NumberOfAppointments()
                << " appoinment(s)\n" << endl;

        int opp;
        cout << "1.Check Appoinment List" << endl;
        cout << "2.Call Patient" << endl;
        cout << "3.Log Out" << endl;

        cout << "\nEnter You Choice: ";
        cin >> opp;
        cout << opp;

        switch(opp){

            case 1:
                clearConsole();
                welcomeWindow();
                cout << "Showing Patient List>>\n" << endl;
                userAccount.showAllAppointments();

                int o;
                cout << "\nEnter 0 to go back, 1 to exit: ";
                cin >> o;
                switch(o){
                    case 0:
                        clearConsole();
                        afterDoctorLogIn(userAccount);
                        break;

                    case 1:
                        clearConsole();
                        exitWindow();
                        break;
                }
                break;

            case 2:
            {
                int ch, coun = 0;
                do{
                    clearConsole();
                    welcomeWindow();
                    cout << "Showing Current Paitent>>\n" << endl;
                    userAccount.seeNextPatient();

                    cout << "\nEnter 0 to call next, 1 To Go Back: ";
                    cin >> ch;
                    coun++;
                    userAccount.SavePatientList();

                }while(ch != 1 && coun <= userAccount.NumberOfAppointments());

                if(ch == 1){
                    clearConsole();
                    afterDoctorLogIn(userAccount);
                }
                break;
            }
            case 3:
                clearConsole();
                logInWindow();
                break;
        }

        clearConsole();
}

void Manager::DoctorLogIn(){
    welcomeWindow();

    cout << "Doctor LogIn Window>>\n" << endl;

    string email, pass;

    cout << "Email Id: ";
    cin >> email;
    getchar();
    cout << "Password: ";
    cin >> pass;

    Doctor_type_account userAccount;
    bool found = doctorDataBase.searchUser(pass, email, userAccount);

    if(found){
        afterDoctorLogIn(userAccount);
        clearConsole();
    }
    else{
        cout << "Log in Failed" << endl;

        int o;
        cout << "Enter 0 to go back, 1 to try again: ";
        cin >> o;

        if(o == 0){
            clearConsole();
            return;
        }
        if(o == 1){
            clearConsole();
            DoctorLogIn();
        }
    }
}


void Manager::searchDoctor(){

    int numberOfItems = doctorDataBase.idAtKeyOnCityMap("Mirpur");
    cout << numberOfItems << endl;
    Doctor_type_account arr[numberOfItems];
    bool isFound = doctorDataBase.searchByArea("Mirpur", arr);

    if(isFound){
        for(int i = 0; i < numberOfItems; i++){
            Doctor_user_type user;
            arr[i].getUser(user);

            cout << user.getName().toString() << endl;
        }
    }else{
        cout << "not Found" << endl;
    }
}

void Manager::doctorSignUp(){
    welcomeWindow();
    string fName, Mname, Lname, area, city, division, postalCode, roadNo,
            sex, id, regNo, eMail, passWord, speciality, d, m, y;

    int age;

    cout << "Doctor Account Sign up>>\n" << endl;

    cout << "First Name: ";
    cin >> fName;
    cout << "Middle Name: ";
    cin >> Mname;
    cout << "Last Name: ";
    cin >> Lname;

    NameType name;
    name.First_name(fName);
    name.Mid_name(Mname);
    name.Last_name(Lname);

    cout << "\nYour Birth>>" << endl;
    cout << "Day: ";
    cin >> d;
    cout << "Month: ";
    cin >> m;
    cout << "Year: ";
    cin >> y;

    DateType date;
    date.Day(d);
    date.Month(m);
    date.Year(y);

    cout << "\nYour office Address>>" << endl;
    cout << "Area: ";
    cin >> area;
    cout << "City: ";
    cin >> city;
    cout << "Division: ";
    cin >> division;
    cout << "Postal Code: ";
    cin >> postalCode;
    cout << "Road Number: ";
    cin >> roadNo;

    AddressType add;
    add.Area(area);
    add.City(city);
    add.Divison(division);
    add.Postal_code(postalCode);
    add.Road_no(roadNo);

    cout << "Sex: ";
    cin >> sex;
    cout << "Age: ";
    cin >> age;
    cout << "Voter ID: ";
    cin >> id;
    cout << "Your area of expertise: ";
    cin >> speciality;
    cout << "Your Doctor's Registration Number: ";
    cin >> regNo;
    cout << "Enter Your Email Address: ";
    cin >> eMail;
    cout << "Enter a new Password: ";
    cin >> passWord;

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

    doctorDataBase.add(newAccount, true);

    int o;

    cout << "\n\nEnter 0 to go back, 1 to exit>> ";
    cin >> o;
    clearConsole();
    if(o == 0) signUpWindow();
    else exitWindow();
}

void Manager::patientSignUp(){


    string fName, Mname, Lname, area, city, division, postalCode, roadNo,
            sex, id, eMail, passWord, d, m, y;

    int age;
    Patient_type_account newAccount;
    Patient_user_type u;
    NameType name;
    DateType date;
    AddressType add;

    bool clearToSave = false;

    while(!clearToSave){

        welcomeWindow();
        cout << "Patient Account Sign up>>\n" << endl;

        cout << "First Name: ";
        cin >> fName;
        cout << "Middle Name: ";
        cin >> Mname;
        cout << "Last Name: ";
        cin >> Lname;

        name.First_name(fName);
        name.Mid_name(Mname);
        name.Last_name(Lname);

        cout << "\nYour Birth>>" << endl;
        cout << "Day: ";
        cin >> d;
        cout << "Month: ";
        cin >> m;
        cout << "Year: ";
        cin >> y;

        date.Day(d);
        date.Month(m);
        date.Year(y);

        cout << "\nYour home Address>>" << endl;
        cout << "Area: ";
        cin >> area;
        cout << "City: ";
        cin >> city;
        cout << "Division: ";
        cin >> division;
        cout << "Postal Code: ";
        cin >> postalCode;
        cou t << "Road Number: ";
        cin >> roadNo;

        add.Area(area);
        add.City(city);
        add.Divison(division);
        add.Postal_code(postalCode);
        add.Road_no(roadNo);

        cout << "Sex: ";
        cin >> sex;
        cout << "Age: ";
        cin >> age;
        cout << "Voter ID: ";
        cin >> id;
        cout << "Enter Your Email Address: ";
        cin >> eMail;
        cout << "Enter a new Password: ";
        cin >> passWord;

        u.setName(name);
        u.setAddress(add);
        u.setBirthDate(date);
        u.setSex(sex);
        u.setAge(age);
        u.setId(id);
        u.setEmail(eMail);

        newAccount.set_account_number(eMail);
        newAccount.set_password(passWord);
        newAccount.setUser(u);
    }

    if(clearToSave){
        patientDataBase.add(newAccount, true);

        ofstream FILE;
        FILE.open("PatientPassList.txt", std::ofstream::out | std::ofstream::app);

        if(FILE.is_open()){
            FILE << newAccount.get_password() << endl;
            FILE << newAccount.get_account_number() << endl;
        }
    }

}


void Manager::searchDoctorWindow(string id, Patient_type_account& userAcc){

    welcomeWindow();

    cout << "Search Doctor Window>>\n" << endl;

    int opp;

    while(opp != 4){

        cout << "1.Search By Name " << endl;
        cout << "2.Search By Doctor's ID "  << endl;
        cout << "3.List nearest Doctors" << endl;
        cout << "4.Go Back" << endl;

        cout <<"\nEnter Your choice: ";
        cin >> opp;

        switch(opp){
            case 1:
                clearConsole();
                searchByName(id, userAcc);
                break;

            case 2:
                clearConsole();
                searchByDoctorId(id, userAcc);
                break;

            case 3:
                clearConsole();
                searchByArea(id, userAcc);
                break;

            case 4:
                clearConsole();
                PatientLoggedInWindow(userAcc);
                break;
        }

    }


}

void Manager::searchByName(string id, Patient_type_account& PuserAcc){
    welcomeWindow();

    cout << "Searching Doctor By Name>>\n" << endl;

    getchar();

    string name;
    cout << "Enter Name: ";
    getline(cin, name);

    int numberOfFoundResult = doctorDataBase.idAtKeyOnNameMap(name);
    Doctor_type_account arr[numberOfFoundResult];
    bool found = doctorDataBase.searchByName(name, arr);

    clearConsole();
    welcomeWindow();

    cout << "Searching Doctor By Name>>\n" << endl;
    cout << "Showing Results for " << name << "\n" << endl;

    if(found){

        for(int i = 0; i < numberOfFoundResult; i++){
            Doctor_user_type user;
            arr[i].getUser(user);

            cout << (i+1) << "." << "Name: " << user.getName().get_name() << endl;
            cout << "  Area Of Expertise: " << user.getSpeciality() << endl;
        }

        int index;
        cout << "\nEnter 0 to go Back, Serial Numbers to Show: ";
        cin >> index;

        if(index == 0) {
            clearConsole();
            return;
        }
        else if(index <= numberOfFoundResult+1){
            clearConsole();
            welcomeWindow();

            cout << "Showing Doctor's Profile>>\n" << endl;

            Doctor_user_type user;
            arr[index-1].getUser(user);

            cout << "Name: " << user.getName().get_name() << endl;
            cout << "Email Id: " << user.getEmail() << endl;
            cout << "Area of Expertise: " << user.getSpeciality() << endl;
            cout << "Sex: " << user.getSex() << endl;

            string cmd;
            cout << "\nDo you want to Book an Appointment: ";
            cin >> cmd;


            if(cmd == "yes" || cmd ==  "Yes"){
                arr[index-1].LoadPatientList();
                bool added = arr[index-1].add_patient(id,true);

                if(added)   cout << "\nAppointment Booked Sucessfully!" << endl;
                else    cout << "\nYou Already Have an Pending Appontment!" << endl;

                int o;
                cout << "\nEnter 0 to Go back, 1 to Exit: ";
                cin >> o;

                if(o == 0) {
                    clearConsole();
                    getchar();
                    searchDoctorWindow(id, PuserAcc);
                }
                else{
                    clearConsole();
                    exitWindow();
                }
            }
            else if(cmd == "No" || cmd == "no"){
                clearConsole();
                getchar();
                searchDoctorWindow(id, PuserAcc);
            }
        }
        else{
            cout << "Wrong Input" << endl;
            exitWindow();
        }
    }

    else{
        cout << "seems like you got the wrong doctor !" << endl;

        int comand;
        cout << "Enter 0 to Go Back, 1 to Try Again: ";
        cin >> comand;

        if(comand == 0){
            clearConsole();
            searchDoctorWindow(id, PuserAcc);
        }
        else if(comand == 1){
            clearConsole();
            searchByName(id, PuserAcc);
        }
    }
}

void Manager::searchByDoctorId(string id, Patient_type_account& PuserAcc){
    clearConsole();
    welcomeWindow();

    cout << "SearchBy Doctor's ID Window>>\n" << endl;

    string docId;
    cout << "Doctor's Id: ";
    cin >> docId;

    Doctor_type_account DuserAcc;
    bool found = doctorDataBase.searchById(docId, DuserAcc);

    if(found){
        Doctor_user_type user;
        DuserAcc.getUser(user);
        DuserAcc.LoadPatientList();

        clearConsole();
        welcomeWindow();

        cout << "Showing Search Results for " << docId << ">> \n" << endl;

        cout << "Name: " << user.getName().get_name() << endl;
        cout << "Email Id: " << user.getEmail() << endl;
        cout << "Area of Expertise: " << user.getSpeciality() << endl;
        cout << "Sex: " << user.getSex() << endl;

        string cmd;
        cout << "\nDo you want to Book an Appointment: ";
        cin >> cmd;

        if(cmd == "yes" || cmd ==  "Yes"){

            bool added = DuserAcc.add_patient(id,true);

            if(added)   cout << "\nAppointment Booked Sucessfully!" << endl;
            else    cout << "\nYou Already Have an Pending Appontment!" << endl;

            int o;
            cout << "\nEnter 0 to Go back, 1 to Exit: ";
            cin >> o;

            if(o == 0) {
                clearConsole();
                getchar();
                searchDoctorWindow(id, PuserAcc);
            }
            else{
                clearConsole();
                exitWindow();
            }
        }
        else if(cmd == "No" || cmd == "no"){
            clearConsole();
            getchar();
            searchDoctorWindow(id, PuserAcc);
        }
    }
    else{
        cout << "Not Found !";

        int comand;
        cout << "Enter 0 to Go Back, 1 to Try Again: ";
        cin >> comand;

        if(comand == 0){
            clearConsole();
            searchDoctorWindow(id, PuserAcc);
        }
        else if(comand == 1){
            clearConsole();
            searchByDoctorId(id, PuserAcc);
        }
    }
}

void Manager::searchByArea(string id, Patient_type_account& PuserAcc){
    clearConsole();
    welcomeWindow();

    cout << "Showing All Doctor's Near to you>>\n" << endl;

    Patient_user_type Puser;
    PuserAcc.getUser(Puser);

    Doctor_type_account DuserAcc;
    int numberOfDoc = doctorDataBase.idAtKeyOnCityMap(Puser.getAddress().get_Area());
    Doctor_type_account arr[numberOfDoc];
    bool found = doctorDataBase.searchByArea(Puser.getAddress().get_Area(), arr);

    if(found){

        for(int i = 0; i < numberOfDoc; i++){
            Doctor_user_type user;
            arr[i].getUser(user);

            cout << (i+1) << "." << "Name: " << user.getName().get_name() << endl;
            cout << "  Area Of Expertise: " << user.getSpeciality() << endl;
        }

        int index;
        cout << "\nEnter 0 to go Back, Serial Numbers to Show: ";
        cin >> index;

        if(index == 0) {
            clearConsole();
            return;
        }
        else if(index <= numberOfDoc+1){
            clearConsole();
            welcomeWindow();

            cout << "Showing Doctor's Profile>>\n" << endl;

            Doctor_user_type user;
            arr[index-1].getUser(user);

            cout << "Name: " << user.getName().get_name() << endl;
            cout << "Email Id: " << user.getEmail() << endl;
            cout << "Area of Expertise: " << user.getSpeciality() << endl;
            cout << "Sex: " << user.getSex() << endl;

            string cmd;
            cout << "\nDo you want to Book an Appointment: ";
            cin >> cmd;


            if(cmd == "yes" || cmd ==  "Yes"){
                arr[index-1].LoadPatientList();
                bool added = arr[index-1].add_patient(id,true);

                if(added)   cout << "\nAppointment Booked Sucessfully!" << endl;
                else    cout << "\nYou Already Have an Pending Appontment!" << endl;

                int o;
                cout << "\nEnter 0 to Go back, 1 to Exit: ";
                cin >> o;

                if(o == 0) {
                    clearConsole();
                    getchar();
                    searchDoctorWindow(id, PuserAcc);
                }
                else{
                    clearConsole();
                    exitWindow();
                }
            }
            else if(cmd == "No" || cmd == "no"){
                clearConsole();
                getchar();
                searchDoctorWindow(id, PuserAcc);
            }
        }
        else{
            cout << "Wrong Input" << endl;
            exitWindow();
        }
    }

    else{
        cout << "Where do You Live At!" << endl;
        cout << "North Pole? \n" << endl;

        int comand;
        cout << "Enter 0 to Go Back, 1 to Try Again: ";
        cin >> comand;

        if(comand == 0){
            clearConsole();
            searchDoctorWindow(id, PuserAcc);
        }
        else if(comand == 1){
            clearConsole();
            searchByArea(id, PuserAcc);
        }
    }


}




























