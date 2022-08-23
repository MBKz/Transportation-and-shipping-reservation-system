#ifndef TRANSPORT_H
#define TRANSPORT_H
#include<Date.h>
#include<string.h>
#include<iostream>
using namespace std;
class Transport
{
    public:
        Transport();
        Transport(int SN,char Brand[15], int Speed,char Category,char Type,double Lenght,int minWight,int maxWight,Date mdate,int bker);
        string getName();
        virtual bool Warning(){return 0;};
        virtual ~Transport();
         void set_SN(int);
         void set_Speed(int );
         void set_minWight(int );
         void set_maxWight(int );
         void set_Lenght(double );
         void set_Category(char);
         void set_Type(char);
         void set_Brand(char*);
         int get_SN();
         int getBker(){return bker;}
         int get_Speed();
         int get_minWight();
         int get_maxWight();
         double get_Lenght();
         char get_Category();
         char get_Type();
         char* get_Brand();
         void print();
         Date get_mdate();
    protected:
    int SN,Speed,minWight,maxWight,bker;
    double Lenght;
    char Brand[15];
    char Type,Category;
    Date mdate;
};
#endif // TRANSPORT_H
