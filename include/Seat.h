#ifndef SEAT_H
#define SEAT_H
#include<Seat.h>
class Seat
{
    public:
        Seat();
        Seat(bool Book,int numberOfSeat,double w_bag);
        void print();
        double getWight(){return w_bag;}
        int getNumberOfSeat(){return numberOfSeat;}
        bool getState(){return Book;}
        virtual ~Seat();
    private:
        int numberOfSeat;
        bool Book;
        double w_bag;
};

#endif // SEAT_H
