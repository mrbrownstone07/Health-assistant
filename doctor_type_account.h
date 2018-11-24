#ifndef DOCTOR_TYPE_ACCOUNT_H_INCLUDED
#define DOCTOR_TYPE_ACCOUNT_H_INCLUDED
#include "account_type.cpp"
#include "doctorusertype.cpp"
#include "review_handler.cpp"
#include "patient_list_handler.cpp"

class Doctor_type_account : public Account_type{
    private:
        Doctor_user_type user;
        Review_handler new_review_handler;
        Patient_List_Handler patient_list;


    public:
        Doctor_type_account();
        string toString();
        void setUser(Doctor_user_type);
        void getUser(Doctor_user_type&);
        void post_review(Review_type newReview);
        void get_review(Review_type& newReview);
        void print_reviews();
        int getNumberOfReviews();
        void showAllAppointments();
        bool add_patient(string id, bool);
        int NumberOfAppointments();
        void seeNextPatient();
        void LoadPatientList();
        void SavePatientList();
};


#endif // DOCTOR_TYPE_ACCOUNT_H_INCLUDED
