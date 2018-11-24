#ifndef DOCTORUSERTYPE_H_INCLUDED
#define DOCTORUSERTYPE_H_INCLUDED
#include "useritemtype.cpp"

class Doctor_user_type : public User_type{
    private:
        string doctor_id;
        string doctor_registration_number;
        string speciality;
    public:
        void setId(string);
        void setRegistrationNumber(string);
        void setSpeciality(string);

        string getId();
        string getRegistrationNumber();
        string getSpeciality();

        string toString();
};


#endif // DOCTORUSERTYPE_H_INCLUDED
