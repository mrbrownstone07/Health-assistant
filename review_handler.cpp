#include "review_handler.h"

void Review_handler::post_review(Review_type newReview){
    review_container.enqueue(newReview);
}

void Review_handler::get_review(Review_type& item){
    review_container.dequeue(item);
    review_container.enqueue(item);
}

void Review_handler::print_reviews(){
    Review_type item;
    for(int i = 0; i<review_container.lengthIs(); i++){
        review_container.dequeue(item);
        cout << item.get_name_of_poster() << endl;
        cout << item.get_review() << endl;

        review_container.enqueue(item);
    }
}

int Review_handler::get_number_of_reviews(){
    return review_container.lengthIs();
}
