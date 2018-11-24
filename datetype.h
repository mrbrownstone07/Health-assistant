#ifndef DATETYPE_H_INCLUDED
#define DATETYPE_H_INCLUDED

enum RelationType{Greater, Equal, Less};

class DateType{
    private:
        string Null = "\0";
        string day;
        string month;
        string year;

    public:
        DateType();

        void Day(string);
        void Month(string);
        void Year(string);

        string get_day();
        string get_month();
        string get_year();

        RelationType compare_To(DateType);

        string toString();
};


#endif // DATETYPE_H_INCLUDED
