#ifndef CIVILAERIAL_H
#define CIVILAERIAL_H
#include <Aerial.h>
class CivilAerial : public Aerial
{
    public:
        CivilAerial();
        CivilAerial(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int numOfEngines,double Lenght,int sets,Date mdate,int bker);
        bool Warning(int);
void set_SN(int SN);
void set_Speed(int Speed);
void set_minWight(int minWight);
void set_maxWight(int maxWight);
void set_Lenght(double Lenght) ;
void set_Category(char Category);
void set_Type(char Type);
void set_Brand(char* Brand) ;
void set_numOfEngines(int numOfEngines) ;
void set_sets (int sets) ;
int get_SN();
int get_Speed();
int get_minWight();
int get_maxWight();
double get_Lenght();
char get_Category();
char get_Type();
char* get_Brand();
int  get_numOfEngines ();
int  get_sets() ;
Date get_mdate();
void print();
virtual ~CivilAerial();
    protected:
        int sets;
};
#endif // CIVILAERIAL_H
