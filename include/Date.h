#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    public:
        Date();
        Date(int Day,int Month, int Year);
        void setDay(int);
        void setMonth(int);
        void setYear(int);
        void Print();

       bool operator <(Date tempDate);
       bool operator >(Date tempDate);
       bool operator ==(Date tempDate);
        virtual ~Date();
    protected:
int Day,Month,Year;
    private:
};
#endif // DATE_H
