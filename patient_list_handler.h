

#ifndef PATIENT_LIST_HANDLER_H_INCLUDED
#define PATIENT_LIST_HANDLER_H_INCLUDED
#include "queuetype.cpp"

class Patient_List_Handler{

    private:
        QueType<string> id_container;

    public:
        void add(string);
        void Remove(string);
        string next();
        string toString();
        int getNumberOfPatients();
        string appointmentDone();
        bool find(string);

};


#endif // PATIENT_LIST_HANDLER_H_INCLUDED
