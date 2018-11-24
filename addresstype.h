#ifndef ADDRESSTYPE_H_INCLUDED
#define ADDRESSTYPE_H_INCLUDED
#include <iostream>
using namespace std;

const string nullStr = "\0";

class AddressType{
    private:
        string city;
        string divison;
        string postal_code;
        string road_no;
        string area;

    public:
        AddressType();

        void City(string);
        void Divison(string);
        void Postal_code(string);
        void Road_no(string);
        void Area(string);

        string toString();

        string get_City();
        string get_Dvision();
        string get_postal_code();
        string get_Road_no();
        string get_Area();
};


#endif // ADDRESSTYPE_H_INCLUDED
