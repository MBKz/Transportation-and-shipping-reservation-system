#ifndef JOURNEY_H
#define JOURNEY_H
#include<iostream>
#include<Date.h>
#include<Seat.h>
using namespace std;
class Journey
{
    public:
        Journey();
        Journey(int journeyNumber,int SN,char transportType,Date date,char from[15],char to[15],int fullseat,int seatnum,Seat* seats, double minWight,double curWight,double maxWight);
        int getJourneyNumber(){return journeyNumber;}
        int getSN(){return SN;}
        char* getFrom(){return from;}
        char* getTo(){return to;}
        void print();
        void setArray(Seat* seats){this->seats=seats;}
        Date getdate(){return date;}
        int getFullSeat(){return fullseat;}
        int get_seatnum(){return seatnum;}
        char getType(){return transportType;}
        Seat* getSeatArray(){return this->seats;}
        virtual ~Journey();
        void printseats();
    private:
        int journeyNumber, SN,seatnum,fullseat;
        char transportType;
        Date date;
        bool wightWrning;
        char from[15],to[15];
        double curWight ,maxWight,minWight;
                Seat* seats;
};

#endif // JOURNEY_H
