#ifndef PATIENTUSERTYPE_H_INCLUDED
#define PATIENTUSERTYPE_H_INCLUDED
#include "useritemtype.cpp"

class Patient_user_type : public User_type{
    private:
        string patient_id;

    public:
        void setId(string);

        string getId();

        string toString();
};


#endif // PATIENTUSERTYPE_H_INCLUDED
