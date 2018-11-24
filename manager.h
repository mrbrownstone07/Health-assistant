#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include <iostream>
#include "doctor_type_database.cpp"
#include "patient_type_database.cpp"
using namespace std;

class Manager{
    private:
        doctor_type_database doctorDataBase;
        Patient_type_database patientDataBase;


        void logInWindow();

            void patientLogIn();
                void PatientLoggedInWindow(Patient_type_account&);
                void searchDoctorWindow(string, Patient_type_account&);
                    void searchByName(string, Patient_type_account&);
                    void searchByDoctorId(string, Patient_type_account&);
                    void searchByArea(string, Patient_type_account&);

            void DoctorLogIn();
                void afterDoctorLogIn(Doctor_type_account&);

        void signUpWindow();
            void doctorSignUp();
            void patientSignUp();

        void ShowTerms();
        void searchDoctor();

    public:
        Manager();
        void mainWindow();



};


#endif // MANAGER_H_INCLUDED
