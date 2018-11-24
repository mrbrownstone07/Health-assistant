#ifndef NAMETYPE_H_INCLUDED
#define NAMETYPE_H_INCLUDED


class NameType{
    private:
        string fname;
        string lname;
        string mname;

    public:
        NameType();

        void First_name(string);
        void Last_name(string);
        void Mid_name(string);

        string toString();
        string get_name();

        string get_first_name();
        string get_last_name();
        string get_mid_name();
};


#endif // NAMETYPE_H_INCLUDED
