#include "CivilAerial.h"
CivilAerial::CivilAerial():Aerial(){
sets=00;
}
CivilAerial::CivilAerial(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int numOfEngines,double Lenght,int sets,Date mdate,int bker)
:Aerial(SN,Brand,Speed,Category,Type,minWight,maxWight,numOfEngines,Lenght,mdate,bker)
{
    this->sets=sets;
}
void CivilAerial::set_SN(int SN){this->SN=SN;}
void CivilAerial::set_Speed(int Speed){this->Speed=Speed;}
void CivilAerial::set_minWight(int minWight){this->minWight=minWight;}
void CivilAerial::set_maxWight(int maxWight){this->maxWight=maxWight;}
void CivilAerial::set_Lenght(double Lenght){this->Lenght=Lenght;}
void CivilAerial::set_Category(char Category){  this->Category=Category;}
void CivilAerial::set_Type(char Type){this->Type=Type;}
void CivilAerial::set_Brand(char* Brand){strcpy(this->Brand,Brand);}
void CivilAerial :: set_numOfEngines(int numOfEngines)  {this->numOfEngines=numOfEngines ;}
void CivilAerial :: set_sets (int sets) {this->sets=sets ;}
int CivilAerial::get_SN(){return SN;}
int CivilAerial::get_Speed(){return Speed;}
int CivilAerial::get_minWight(){return minWight;}
int CivilAerial::get_maxWight(){return maxWight;}
double CivilAerial::get_Lenght(){return Lenght;}
char CivilAerial::get_Category(){return Category;}
char CivilAerial::get_Type(){return Type;}
char* CivilAerial::get_Brand(){return Brand;}
int CivilAerial :: get_numOfEngines () {return numOfEngines ;}
int CivilAerial :: get_sets() {return sets ;}
Date CivilAerial::get_mdate(){return mdate;}
void CivilAerial::print(){Transport::print();}
CivilAerial::~CivilAerial()
{
    //dtor
}
