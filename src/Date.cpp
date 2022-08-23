#include "Date.h"
Date::Date()
{
    Day=0;
    Month=0;
    Year=0;
}
Date::Date(int Day,int Month, int Year)
{
    this->Day=Day;
    this->Month=Month;
    this->Year=Year;
}
bool Date:: operator >(Date tempdate){
    if(this->Year>tempdate.Year){
        return true;
    }else if(this->Year<tempdate.Year){
    return false;
    }
    if(this->Month>tempdate.Month ){
        return true;
    }else if(this->Month < tempdate.Month ){
    return false;
    }
    if(this->Day>tempdate.Day){
        return true;
    }else if (this->Day<tempdate.Day){
    return false;
    }
return false;
}
bool Date:: operator <(Date tempdate){
    if(this->Year<tempdate.Year){
        return true;
    }else if(this->Year>tempdate.Year){
    return false;
    }
    if(this->Month<tempdate.Month ){
        return true;
    }else if(this->Month > tempdate.Month ){
    return false;
    }
    if(this->Day < tempdate.Day){
        return true;
    }else if (this->Day > tempdate.Day){
    return false;
    }
    return false;
}
bool Date:: operator ==(Date tempdate){
    if(this->Year==tempdate.Year && this->Day==tempdate.Day && this->Month==tempdate.Month){
        return true;
    }
    return false;
}
void Date::setDay(int Day){this->Day=Day;}
void Date::setMonth(int Month){this->Month=Month;}
void Date::setYear(int Year){this->Year=Year;}
void Date::Print()
        {
        cout<<"("<<this->Day<<"/"<<this->Month<<"/"<<this->Year<<")"<<endl;

        }
Date::~Date()
{
    //dtor
}
