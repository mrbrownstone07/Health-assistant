#include "patient_list_handler.h"

void Patient_List_Handler::add(string id){
    id_container.enqueue(id);
}

bool Patient_List_Handler::find(string key){
    string temp;
    for(int i = 0; i<id_container.lengthIs(); i++){
        id_container.dequeue(temp);
        id_container.enqueue(temp);
        if(temp == key) return true;
    }
    return false;
}

void Patient_List_Handler::Remove(string id){
    string temp;
    for(int i = 0; i<id_container.lengthIs(); i++){
        id_container.dequeue(temp);
        if(temp != id) id_container.enqueue(temp);
    }
}

int Patient_List_Handler::getNumberOfPatients(){
    return id_container.lengthIs();
}

string Patient_List_Handler::next(){
    string temp;
    id_container.dequeue(temp);
    id_container.enqueue(temp);

    return temp;
}

string Patient_List_Handler::toString(){
    string temp;
    string buffer = "";
    for(int i = 0; i<id_container.lengthIs(); i++){
        id_container.dequeue(temp);
        id_container.enqueue(temp);
        buffer += temp;
    }

    return buffer;
}

string Patient_List_Handler::appointmentDone(){
    string temp;
    id_container.dequeue(temp);
    return temp;

}

