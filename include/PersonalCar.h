#ifndef PERSONALCAR_H
#define PERSONALCAR_H
#include <Wilderness.h>
class PersonalCar : public Wilderness
{
    protected:
        int numofdoors;
    public:
        PersonalCar();
        PersonalCar(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,int numofdoors,Date mdate,int bker);
        void set_numofdoors (int numofdoors) {this->numofdoors=numofdoors;}
        int get_numofdoors () {return numofdoors ;}
        int get_sets() {return numofdoors -1;}
        bool Warning(int);
        int getNumofdoors(){return numofdoors;}
        virtual ~PersonalCar();
};
#endif // PERSONALCAR_H
