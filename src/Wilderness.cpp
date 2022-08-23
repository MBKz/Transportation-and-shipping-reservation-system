#include "Wilderness.h"
#include<Date.h>

Wilderness::Wilderness():Transport(){
    engineVolume = 0;
}
Wilderness::Wilderness(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,Date mdate,int bker)
:Transport(SN,Brand,Speed,Category,Type,Lenght,minWight,maxWight,mdate,bker)
{
    this->engineVolume = engineVolume;
    this->Lenght=Lenght;
}
Wilderness::~Wilderness () {}
