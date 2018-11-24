#ifndef USERITEMTYPE_H_INCLUDED
#define USERITEMTYPE_H_INCLUDED
#include "addresstype.cpp"
#include "datetype.cpp"
#include "nametype.cpp"

class User_type{
    private:
        string emailId;
        string voterId;
        NameType name;
        string sex;
        int age;
        AddressType address;
        DateType birth_date;

    public:
        User_type();

        void setEmail(string);
        void setVoterId(string);
        void setName(NameType);
        void setAge(int);
        void setAddress(AddressType);
        void setBirthDate(DateType);
        void setSex(string);

        NameType getName();
        int getAge();
        AddressType getAddress();
        DateType getBirthDate();
        string getSex();
        string getEmail();
        string getVoterId();

        string toString();
};


#endif // USERITEMTYPE_H_INCLUDED
