#ifndef REVIEW_TYPE_H_INCLUDED
#define REVIEW_TYPE_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Review_type{
    private:
        string review;
        string name_of_poster;

    public:
        void set_review(string);
        string get_review();
        void set_name_of_poster(string);
        string get_name_of_poster();
};


#endif // REVIEW_TYPE_H_INCLUDED
