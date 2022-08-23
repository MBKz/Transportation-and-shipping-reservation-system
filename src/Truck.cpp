#include "Truck.h"
Truck::Truck():Wilderness(){
this->high=00;
}
Truck::Truck(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,double high,Date mdate,int bker)
:Wilderness(SN,Brand,Speed,Category,Type,minWight,maxWight,engineVolume,Lenght,mdate,bker)
{
    this->high=high;
}
bool Truck:: Warning(int war){
if (war + minWight > maxWight) return true ;
else return false ;
}
Truck::~Truck(){}

