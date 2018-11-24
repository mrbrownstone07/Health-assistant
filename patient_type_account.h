#ifndef PATIENT_TYPE_ACCOUNT_H_INCLUDED
#define PATIENT_TYPE_ACCOUNT_H_INCLUDED
#include "account_type.cpp"
#include "patientusertype.cpp"

class Patient_type_account : public Account_type{
    private:
        Patient_user_type user;

    public:
        Patient_type_account();
        void setUser(Patient_user_type);
        void getUser(Patient_user_type&);
        string toString();
};

#endif // PATIENT_TYPE_ACCOUNT_H_INCLUDED
