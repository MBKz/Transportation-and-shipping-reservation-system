#include "PersonalCar.h"


PersonalCar::PersonalCar():Wilderness(){
this->numofdoors=0;
}
PersonalCar::PersonalCar(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,int numofdoors,Date mdate,int bker)
:Wilderness(SN,Brand,Speed,Category,Type,minWight,maxWight,engineVolume,Lenght,mdate,bker)
{
    this->numofdoors=numofdoors;
}
bool PersonalCar:: Warning(int war){
return (war + minWight <= maxWight);
}
PersonalCar::~PersonalCar() {}
