#ifndef AERIAL_H
#define AERIAL_H
#include <Transport.h>
class Aerial : public Transport
{
    public:
        Aerial();
        Aerial(int ,char* , int ,char ,char ,int ,int ,int ,double ,Date,int);
        virtual ~Aerial();
        void set_numOfEngines(int);
        int get_numOfEngines();
    protected:
int numOfEngines;
};
#endif // AERIAL_H
