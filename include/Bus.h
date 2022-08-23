#ifndef BUS_H
#define BUS_H
#include <Wilderness.h>
class Bus : public Wilderness
{
    protected:
        int sets ;
    public:
        Bus();
        Bus(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,int sets,Date mdate,int bker);
        bool Warning(int);
        void print(){
        Transport::print();
        }
        virtual ~Bus();
        void set_sets (int sets) {this->sets=sets;}
        int get_sets () {return sets ;}
};
#endif // BUS_H
