#include "Transport.h"
#include<iostream>
#include<Transport.h>
#include<string.h>
#include<Date.h>
Transport::Transport(){
SN = 0000;
Speed = 000;
Category = 'n';
Type = 'n';
minWight = 000;
maxWight = 000;
Lenght=000;
}
Transport::Transport(int SN,char Brand[15], int Speed,char Category,char Type,double Lenght,int minWight,int maxWight,Date mdate,int bker):mdate(mdate)
{
this->bker=bker;
this->SN=SN;
this->Speed=Speed;
this->Category=Category;
this->Type=Type;
this->minWight=minWight;
this->maxWight=maxWight;
this->Lenght=Lenght;
strcpy(this->Brand,Brand);
}
void Transport::print(){
    switch(this->bker){
case 1:
    cout<<"Personal Car: "<<endl;
    break;
case 2:
    cout<<"Bus: "<<endl;
    break;
case 3:
    cout<<"Truck: "<<endl;
    break;
case 4:
    cout<<"Civil Aerial: "<<endl;
    break;
case 5:
    cout<<"Trade Aerial: "<<endl;
    break;
    }
cout<<"Sn: "<<SN<<endl;
cout<<"Brand: "<<Brand<<endl;
if (bker==1 || bker==2 || bker==3)    cout<<"Speed(km): "<<Speed<<endl;
if (bker ==4 || bker==5) cout<<"Speed(km): "<<Speed<<" which equal "<<(Speed/1.852)<<" by (knot)"<<endl;
if (Category == 'I')        cout<<"Category: International"<<endl;
if (Category == 'G')        cout<<"Category: Government"<<endl;
if (Category == 'P')        cout<<"Category: Personal"<<endl;
if (Type == 'T')            cout<<"Type: Trade"<<endl;
if (Type == 'C')            cout<<"Type: Civil"<<endl;
cout<<"Lenght: "<<Lenght<<" (m)"<<endl;
cout<<"minWight: "<<minWight<<endl;
cout<<"maxWight: "<<maxWight<<endl;
cout<<"Date: ";
this->mdate.Print();
}
void Transport::set_SN(int SN){this->SN=SN;}
void Transport::set_Speed(int Speed){this->Speed=Speed;}
void Transport::set_minWight(int minWight){this->minWight=minWight;}
void Transport::set_maxWight(int maxWight){this->maxWight=maxWight;}
void Transport::set_Lenght(double Lenght){this->Lenght=Lenght;}
void Transport::set_Category(char Category){  this->Category=Category;}
void Transport::set_Type(char Type){this->Type=Type;}
void Transport::set_Brand(char* Brand){strcpy(this->Brand,Brand);}
int Transport::get_SN(){return SN;}
int Transport::get_Speed(){return Speed;}
int Transport::get_minWight(){return minWight;}
int Transport::get_maxWight(){return maxWight;}
double Transport::get_Lenght(){return Lenght;}
char Transport::get_Category(){return Category;}
char Transport::get_Type(){return Type;}
char* Transport::get_Brand(){return Brand;}
Date Transport::get_mdate(){return mdate;}
Transport::~Transport()
{
    //dtor
}
