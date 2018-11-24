#ifndef REVIEW_HANDLER_H_INCLUDED
#define REVIEW_HANDLER_H_INCLUDED
#include "review_type.cpp"
#include "queuetype.cpp"
class Review_handler{
    private:
        QueType<Review_type> review_container;


    public:
        void post_review(Review_type);
        void get_review(Review_type&);
        void print_reviews();
        int get_number_of_reviews();
};


#endif // REVIEW_HANDLER_H_INCLUDED
