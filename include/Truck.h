#ifndef TRUCK_H
#define TRUCK_H
#include <Wilderness.h>
class Truck : public Wilderness
{
    protected:
        double high;
    public:
        Truck();
        Truck(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,double high,Date mdate,int bker);
        bool Warning(int);
        virtual ~Truck();
        void set_high(double hight) {this->high=high;}
        double get_high(){return high;}
};
#endif // TRUCK_H
