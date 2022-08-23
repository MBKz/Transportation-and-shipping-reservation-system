#include "TradeAerial.h"

TradeAerial::TradeAerial():Aerial()
{
    //ctor
}
TradeAerial::TradeAerial(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int numOfEngines,double Lenght,Date mdate,int bker)
:Aerial(SN,Brand,Speed,Category,Type,minWight,maxWight,numOfEngines,Lenght,mdate,bker){
}
bool TradeAerial:: Warning(int war){
return war+minWight>maxWight;
}
TradeAerial::~TradeAerial()
{
    //dtor
}
