#include <Bus.h>
Bus::Bus():Wilderness(){
this->sets=0;
}
Bus::Bus(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,int sets,Date mdate,int bker)
  : Wilderness(SN,Brand,Speed,Category,Type,minWight,maxWight,engineVolume,Lenght,mdate,bker)
  {
      this->sets=sets ;
  }

Bus::~Bus(){}
