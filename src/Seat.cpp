#include "Seat.h"
#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
Seat::Seat()
{
     numberOfSeat = 0;
    Book=false;
    w_bag=00;
}
Seat::Seat(bool Book,int numberOfSeat,double w_bag)
{
    this->numberOfSeat=numberOfSeat;
    this->Book=Book;
    this->w_bag=w_bag;
}
void Seat::print()
{
   cout<<"\tSeat Number: "<<numberOfSeat;
    if (numberOfSeat>=100)   cout<<"\tWight: "<<w_bag<< endl;
    else cout<<"\t\tWight: "<<w_bag<< endl;
}
Seat::~Seat()
{
    //dtor
}
