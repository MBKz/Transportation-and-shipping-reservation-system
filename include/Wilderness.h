#ifndef WILDERNESS_H
#define WILDERNESS_H
#include <Transport.h>
class Wilderness : public Transport
{
public:
    Wilderness();
    Wilderness(int SN,char Brand[15], int Speed,char Category,char Type,int minWight,int maxWight,int engineVolume,double Lenght,Date mdate,int bker);
    virtual ~Wilderness();
    void  set_engineVolume (int engineVolume){this->engineVolume=engineVolume;}
    void  set_Lenght (double Lenght){this->Lenght=Lenght;}
    int   get_engineVolume (){return engineVolume;}
    double  get_Lenght (){return Lenght;}
protected:
    int engineVolume;
    double Lenght;
};
#endif // WILDERNESS_H
