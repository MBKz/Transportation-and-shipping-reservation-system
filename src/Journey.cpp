#include "Journey.h"
#include<Date.h>
#include<string.h>
Journey::Journey()
{
    journeyNumber = 0;
    SN=0;
    transportType='n';
    minWight=0;
    curWight =00;
    maxWight = 0;
    seatnum=0;
}
Journey::Journey(int journeyNumber,int SN,char transportType,Date date,char from[15],char to[15],int fullseat,int seatnmu,Seat* seats,double minWight,double curWight,double maxWight):date(date)
{
    this->fullseat=fullseat;
    this->journeyNumber = journeyNumber;
    this->SN=SN;
    this->transportType=transportType;
    this->curWight=curWight;
    this->maxWight=maxWight;
    this->seats=seats;
    this->minWight=minWight;
    this->seatnum=seatnmu;
    this->SN=SN;
    strcpy(this->to,to);
    strcpy(this->from,from);
}
void Journey::print()
{
    cout<<"Journey Number: "<<journeyNumber<<endl;
    cout<<"Sn: "<<SN<<endl;
    if (transportType == 'T' || transportType == 't')            cout<<"Type: Trade"<<endl;
    if (transportType == 'C' || transportType == 'c')            cout<<"Type: Civil"<<endl;
    cout<<"Journey Date: ";
    date.Print();
    cout<<"From: "<<from<<endl;
    cout<<"To: "<<to<<endl;
    if(transportType == 'C' || transportType == 'c')
    {
        cout<<"Seats Numbers : "<<seatnum<<endl;
        cout<<"Seats:"<<endl;
        for(int i=0; i<fullseat; i++)
        {
            if(seats[i].getState())
            {
                seats[i].print();
            }
        }
    }
    cout<<"Min Wight: "<<minWight<<endl;
    int temp=0;
    cout<<"Current Wight: "<<curWight<<endl;
    if(transportType == 'C' || transportType == 'c'){
        if(curWight > 25 * seatnum){
                for(int i =0 ; i <seatnum;i++){
                    temp+=seats[i].getWight();
                }
        }
    }
    cout<<"goods Wight: "<< (curWight - minWight -temp)<<endl;
    cout<<"Max Wight: "<<maxWight<<endl;
    cout<<"____________________________________________"<<endl;
}
void Journey::printseats()
{
    for(int i=1; i<=seatnum; i++)
    {
        seats[i].print();
    }
}
Journey::~Journey()
{
}
