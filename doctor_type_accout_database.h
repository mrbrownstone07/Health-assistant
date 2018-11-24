#ifndef DOCTOR_TYPE_ACCOUT_DATABASE_H_INCLUDED
#define DOCTOR_TYPE_ACCOUT_DATABASE_H_INCLUDED
#include "Unosorted_type_linkedlist.cpp"
#include "pqtype.h"
enum LoginResultType{SUCESSFUL,UNSUCESSFUL};
class Doctor_type_account_dataBase : public pqtype{
    private:
        UnsortedLinkedList<Doctor_type_account> doctor_type_account_container;

    public:
        void add_account(Doctor_type_account& a);
        void get_account(Doctor_type_account& a, bool found);
        void search_account_by_name(string);
        void search_account_by_id(string);
        void search_account_by_account_number(string);
        void post_for_login(string, string);
};


#endif // DOCTOR_TYPE_ACCOUT_DATABASE_H_INCLUDED
