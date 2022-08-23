#include "Aerial.h"
Aerial::Aerial():Transport(){
numOfEngines=00;
Lenght=00;

}
Aerial::Aerial(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int numOfEngines,double Lenght,Date mdate,int bker)
   :Transport(SN,Brand,Speed,Category,Type,Lenght,minWight,maxWight,mdate,bker)
{
    this->numOfEngines=numOfEngines;
    this->Lenght=Lenght;
}
Aerial::~Aerial()
{
    //dtor
}
void Aerial::set_numOfEngines(int numOfEngines)
{
    this->numOfEngines=numOfEngines;
}
int Aerial::get_numOfEngines()
{
    return numOfEngines;
}
