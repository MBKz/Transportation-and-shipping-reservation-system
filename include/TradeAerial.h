#ifndef TRADEAERIAL_H
#define TRADEAERIAL_H
#include <Aerial.h>
class TradeAerial : public Aerial
{
    public:
        TradeAerial();
        TradeAerial(int ,char* , int ,char ,char ,int ,int ,int ,double ,Date,int);
        bool Warning(int);
        virtual ~TradeAerial();
};

#endif // TRADEAERIAL_H
