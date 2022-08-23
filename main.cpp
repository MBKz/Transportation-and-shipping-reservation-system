#include <iostream>
#include<Date.h>
#include<CivilAerial.h>
#include<list>
#include<Seat.h>
#include<Journey.h>
#include<Design.h>
#include<PersonalCar.h>
#include<Transport.h>
#include<Truck.h>
#include<Bus.h>
#include<TradeAerial.h>
#include <bits/stdc++.h>
#include<fstream>
#include<math.h>
#include<ctime>
#include <sys/stat.h>
#include<conio.h>
#include<windows.h>
using namespace std;
Date today;
//****************************************************************
int getInteger(int o)
{
    char input[20];
    int result[20],j=0;;
lable:
    cin.sync();
    cin>>input;
    int l = sizeof(input)/sizeof(char);
    for (int i =0 ; i < l; i++)
    {
        if(input[i] == '\0')
        {
            break;
        }
        if(input[0] == '\n')
        {
            cout<<"Can't Be Empty"<<endl;
            goto lable;
        }
        if(input[i]>'9' || input[i]<'0')
        {
            cout<<"Enter Only Integers"<<endl;
            goto lable;
        }
        result[i]= input[i] -48;
        j++;
    }
    int sum=0;
    for(int i =0; i<j; i++)
    {
        sum = sum*10 + result[i];
    }
    j=0;
    if(sum==0 && o == 1)
    {
        cout<<"cant be Zero"<<endl;
        goto lable;
    }
    return sum;

}
double getDouble(int o)
{


    char input[30];
    int result[30];
    int j=0;
    bool point=false;
lable:
    //cin.sync();
    cin>>input;
    int l = sizeof(input)/sizeof(char);
    for (int i =0 ; i < l; i++)
    {
        if(input[i] == '\0')
        {
            break;
        }
        if(input[0] == '\n')
        {
            goto lable;
        }
        if(i==0 && input[0]=='.')
        {
            goto lable;
        }
        if(input[i]=='.')
        {
            result[i]= input[i];
            j++;
            continue;
        }
        if(input[i]>'9' || input[i]<'0')
        {
            cout<<"Enter Only Integers"<<endl;
            goto lable;
        }
        result[i]= input[i] -48;
        j++;
    }
    int z=1;
    long double sum=0.0;
    point=false;
    long double temp=0;
    for(int i =0; i<j; i++)
    {
        if(result[i] == 46)
        {
            point = true;
            continue;
        }
        if(point)
        {
            temp = pow(10,z);
            sum = sum + result[i]/temp;
            z++;

        }
        else
        {
            sum = sum*10 + result[i];
        }
    }
    j=0;
    if(sum==0 && o == 1)
    {
        cout<<"cant be Zero"<<endl;
        goto lable;
    }
    return sum;

}
//****************************************************************
template <class T> class Node
{
public:
    T data;
    Node* next;

};
//****************************************************************
template <class T> class LinkedList
{

    int length;
    Node<T>* head;
public:
    LinkedList<T>()
    {
        this->length = 0;
        this->head = NULL;
    }
    ~LinkedList<T>()
    {
    }
    void add(T data)
    {
        Node<T>* node = new Node<T>();
        node->data = data;
        node->next = this->head;
        this->head = node;
        this->length++;
    }
    void print()
    {
        Node<T>* head = this->head;
        int i = 1;
        while(head)
        {
            std::cout << i << ": " << head->data.print() << std::endl;
            head = head->next;
            i++;
        }
    }
    Node<T>* get_head()
    {
        return head;
    }
    int getLenght()
    {
        return length;
    }
};
LinkedList<Transport*> transportList;
LinkedList<Journey> journeyList;
LinkedList<Journey> JL;
//****************************************************************
void transportListprint()
{
    Transport* c;
    Node<Transport*>* head = transportList.get_head();
    int i = 1;
    while(head)
    {
        c = head->data;
        if(c->getBker() == 1)
        {
            PersonalCar* p= (PersonalCar*) c;
            p->print();
        }
        if(c->getBker() == 2)
        {
            Bus* p= (Bus*) c;
            p->print();
        }
        if(c->getBker() == 3)
        {
            Truck* p= (Truck*) c;
            p->print();
        }
        if(c->getBker() == 4)
        {
            CivilAerial* p= (CivilAerial*) c;
            p->print();
        }
        if(c->getBker() == 5)
        {
            TradeAerial* p= (TradeAerial*) c;
            p->print();
        }
        cout<<"*******************************"<<endl;
        head = head->next;
        i++;

    }

}
//****************************************************************
void journeyListprint()
{
    Node<Journey>* cur = journeyList.get_head();
    int i = 1;
    while(cur!=NULL)
    {
        cur->data.print();
        cur= cur->next;
        i++;
    }
}
//****************************************************************
void finalFunctions()
{
    fstream journeyFile,transportFile;
    Node<Transport*>* cur= transportList.get_head();
    if(transportList.get_head() == NULL)
    {
        return;
    }
    transportFile.open("transport.bin", ios::binary | ios::out);

    do
    {
        if(cur->data->getBker() == 1)
        {

            PersonalCar* p = (PersonalCar*) cur->data;

            transportFile.write((char*) p,sizeof(PersonalCar));
        }
        else if (cur->data->getBker() == 2)
        {
            Bus* p = (Bus*) cur->data;
            transportFile.write((char*) p,sizeof(Bus));
        }
        else if (cur->data->getBker() == 3)
        {

            Truck* p = (Truck*) cur->data;
            transportFile.write((char*) p,sizeof(Truck));

        }
        else if (cur->data->getBker() == 4)
        {

            CivilAerial* p = (CivilAerial*) cur->data;
            transportFile.write((char*) p,sizeof(CivilAerial));

        }
        else if (cur->data->getBker() == 5)
        {

            TradeAerial* p = (TradeAerial*) cur->data;
            transportFile.write((char*) p,sizeof(TradeAerial));
        }
        cur=cur->next;
    }
    while(cur!=NULL);
    transportFile.close();

    if(journeyList.get_head() == NULL)
    {
        return;
    }
    Node<Journey>* jcur= journeyList.get_head();
    Journey j;
    journeyFile.open("journey.bin",ios::binary | ios::out);
    jcur = journeyList.get_head();
    Seat seat;
    do
    {
        j = jcur->data;
        journeyFile.write((char*) &j,sizeof(Journey));
        if(j.getType() == 'c' || j.getType() == 'C')
        {
            for(int i =0 ; i<j.getFullSeat(); i++)
            {
                journeyFile.write((char*) &(j.getSeatArray()[i]),sizeof(Seat));
            }
        }
        jcur= jcur->next;
    }
    while(jcur!=NULL);
    journeyFile.close();
}
//****************************************************************
void openFiles()
{
    unsigned int pointer;
    fstream journeyFile,transportFile;
    Transport t;
    Transport* temp;

    transportFile.open("transport.bin",ios::binary | ios::in);
    if(!transportFile.is_open())
    {
        return ;
    }
    do
    {

        transportFile.read((char*) &t,sizeof(Transport));
        if(transportFile.tellp() == -1)
        {
            break;
        }
        if(t.getBker() == 1)
        {
            transportFile.seekg(-72,ios::cur);
            PersonalCar* p = new PersonalCar();
            transportFile.read((char*) p,sizeof(PersonalCar));
            temp = (Transport*) p;
            transportList.add(temp);
            //temp->print();
        }
        else if (t.getBker() == 2)
        {
            transportFile.seekg(-72,ios::cur);
            Bus* p = new Bus();
            transportFile.read((char*) p,sizeof(Bus));
            temp = (Transport*) p;
            transportList.add(temp);
            //        p.print();
        }
        else if (t.getBker() == 3)
        {
            transportFile.seekg(-72,ios::cur);
            Truck* p = new Truck();
            transportFile.read((char*) p,sizeof(Truck));
            temp = (Transport*) p;
            transportList.add(temp);
            //      p.print();
        }
        else if (t.getBker() == 4)
        {
            transportFile.seekg(-72,ios::cur);
            CivilAerial* p = new CivilAerial();
            transportFile.read((char*) p,sizeof(CivilAerial));
            temp = (Transport*) p;
            transportList.add(temp);
            //      p.print();
        }
        else if (t.getBker()  == 5)
        {
            transportFile.seekg(-72,ios::cur);
            TradeAerial* p = new TradeAerial();
            transportFile.read((char*) p,sizeof(TradeAerial));
            temp = (Transport*) p;
            transportList.add(temp);
            //      p.print();
        }
        if(transportFile.tellp() == -1)
        {
            break;
        }
    }
    while(!transportFile.eof());
    transportFile.close();
    Journey j;
    Seat* seats;
    Seat stemp;
    journeyFile.open("journey.bin",ios::binary | ios::in);
    if(!journeyFile.is_open())
    {
        return ;
    }
    journeyFile.seekp(0,ios::end);
    pointer = journeyFile.tellp();
    journeyFile.seekp(0,ios::beg);
    while(!journeyFile.eof() )
    {
        journeyFile.read((char*) &j,sizeof(Journey));
        if(j.getType() == 'C' || j.getType() == 'c')
        {
            seats = new Seat[j.getFullSeat()];
            for(int i=0; i<j.getFullSeat(); i++)
            {
                journeyFile.read((char*) &stemp,sizeof(Seat));
                seats[i] =  Seat(stemp.getState(),stemp.getNumberOfSeat(),stemp.getWight());
            }
        }
        j.setArray(seats);
        journeyList.add(j);
        if(journeyFile.tellp() == pointer)
        {
            break;
        }
    }
    journeyFile.close();
    return ;
}
//****************************************************************
Transport* search_transport(int x)
{
    Node<Transport*>* temp;
    if(transportList.get_head() == NULL)
    {
        return NULL;
    }
    if(x==transportList.get_head()->data->get_SN())
    {
        cout<<"transport exist"<<endl;
        return transportList.get_head()->data;
    }
    temp=transportList.get_head()->next;
    while(temp!=NULL)
    {
        if(x==temp->data->get_SN())
        {
            cout<<"transport exist"<<endl;
            return temp->data;
        }
        temp=temp->next;
    }
    cout<<"transport dosen't exist"<<endl;
    return NULL;
}
//****************************************************************
int search_journey()
{
    Node<Journey>* temp = journeyList.get_head();
    int x;
    cout<<"Enter number of Journey you want: ";
    x=getInteger(1);
    if(x==journeyList.get_head()->data.getJourneyNumber())
    {
        cout<<"found"<<endl;
        return temp->data.getJourneyNumber();
    }
    temp=journeyList.get_head()->next;
    do
    {
        if(x==temp->data.getJourneyNumber())
        {
            cout<<"found"<<endl;
            return temp->data.getJourneyNumber();
        }
        cout<<temp->data.getJourneyNumber()<<endl;
        temp=temp->next;
    }
    while(temp!=NULL);
    cout<<"not found"<<endl;
    return -1;
}
//****************************************************************
bool CheackAvilabilite(int SN,Date d)
{
    if(journeyList.get_head() == NULL)
        return true;
    Node<Journey>* temp;
    if(SN==journeyList.get_head()->data.getSN() && d == journeyList.get_head()->data.getdate())
    {
        cout<<"This Transport already have a journey in this day!! You can't Book it"<<endl;
        return false;
    }
    temp=journeyList.get_head()->next;
    while(temp!=NULL)
    {
        if(SN==temp->data.getSN() && d == temp->data.getdate())
        {
            cout<<"This Transport already have a journey in this day!! You can't Book it"<<endl;
            return false;
        }
        temp=temp->next;
    }
    return true;
}
//****************************************************************
void printinformation()
{
    int x,i=0;
    Node<Journey>* myNode=journeyList.get_head();
    cout<<"Enter Number of Transport (SN) : ";
    x=getInteger(1);
    while(myNode!=NULL)
    {
        if(myNode->data.getSN()==x )
        {
            i++;
            cout<<i<<"- ";
            myNode->data.print();
            cout<<":\n";
        }
        myNode=myNode->next;
    }
    if(i==0)
    {
        cout<<"This Transport Has No Journey";
    }
}
//****************************************************************
void newTransport()
{
    Transport*c;
    int SN,q,Speed,minWight,maxWight;
    double Lenght;
    char Category;
    char Brand[25];
    Date mdate;
    int day,month,year,x,y;
    cout<<"Which Transport you want to add? Choose From list "<<endl;
    cout<<"1-Personal Car"<<endl<<"2-Bus"<<endl<<"3-Trade Truck"<<endl<<"4-Civil Aerial"<<endl<<"5-Trade Aerial"<<endl;
    do
    {
        x=getInteger(1);
        if ( !((x==1) || (x==2) || (x==3) || (x==4) || (x==5)) )
        {
            cout << "choose only from the list (*_*) "<<endl;
            continue ;
        }
    }
    while(!((x==1) || (x==2) || (x==3) || (x==4) || (x==5)));
    cout<<"SN : ";
    q=getInteger(1);
    c=search_transport(q);
    if ( c != NULL )
    {
        cout<<"we already have this transport (this SN) ..."<<endl;
        return;
    }
    SN=q;
lable:
    cout << "The date:"<<endl<<"Day: ";
    day=getInteger(1);
    cout<<"Month: ";
    month=getInteger(1);
    cout<<"Year: ";
    year=getInteger(1);

    if(!(day>=1&&day<=30) || !(month>=1&&month<=12) || !(year>=1950&&year<=2019))
    {
        cout<<"Please Enter A logical Date"<<endl;
        goto lable;
    }
    mdate = Date(day,month,year);
    if(mdate>today)
    {
        cout<<"The Date You entered is in The Future Dude!! Enter A logical Date!!"<<endl;
        goto lable;
    }
    cout<<"Max Speed: ";
    Speed=getInteger(1);
    cout<<"Lenght : ";
    Lenght=getDouble(1);
    cout<<"Choose the category from the list: "<<endl<<"1- Personal "<<endl<<"2- Government "<<endl<<"3- International "<<endl;
    do
    {
        y=getInteger(1);
        if ( !((y==1) || (y==2) || (y==3)) )
        {
            cout << "choose only from the list (*_*) "<<endl;
            continue ;
        }
    }
    while(!((y==1) || (y==2) || (y==3)));
    switch(y)
    {
    case 1:
        Category = 'P';
        break;
    case 2:
        Category = 'G';
        break;
    case 3:
        Category = 'I';
        break;
    }
    cout<<"Brand: ";
    cin>>Brand;


    int Doors=0,engineVolume=0,Seats=0,High=0,numberOfEngine=0;
    if(x==1)
    {
        cout<<"Min Wight: ";
        minWight=getDouble(1);
        do
        {
            cout<<"Doors Number (2,4,6) :";
            Doors=getInteger(1);
        }
        while(!((Doors==2)||(Doors==4)||(Doors==6)));
        cout<<"Max Wight: ";
        do
        {
            maxWight=getDouble(1);
            if ( maxWight < ( minWight + (25*(Doors-1))))
            {
                cout << "the max wight dosent make sense (*_*) !! .... reenter ." << endl ;
                cout <<" it should be at least " <<( minWight + (25*(Doors-1))) << endl ;
            }
        }
        while(maxWight < ( minWight + (25*(Doors-1))));
        cout<<"Engine size: ";
        engineVolume=getInteger(1);
        PersonalCar* myTransport = new PersonalCar(SN,Brand,Speed,Category,'C',minWight,maxWight,engineVolume,Lenght,Doors,mdate,x);
        transportList.add(myTransport);
    }
    else if(x==2)
    {
        cout<<"Engine size: ";
        engineVolume=getInteger(1);
        do
        {
            cout<<"Seats Number (between 8->160) :";
            Seats=getInteger(1);
        }
        while ((Seats<8)||(Seats>160));
        cout<<"Min Wight: ";
        minWight=getDouble(1);
        cout<<"Max Wight: ";
        do
        {
            maxWight=getDouble(1);
            if ( maxWight < ( minWight + (25*Seats) ))
            {
                cout << "the max wight dosen't make sense (*_*) !! .... reenter ." << endl << "it should be at least "<<minWight + (25*Seats) <<endl ;
            }
        }
        while(maxWight < ( minWight + (25*Seats)));
        Bus* myTransport = new Bus(SN,Brand,Speed,Category,'C',minWight,maxWight,engineVolume,Lenght,Seats,mdate,x);
        transportList.add(myTransport);
    }
    else if(x==3)
    {
        do
        {
            cout<<"Goods High (between 1->5 ) : ";
            High=getInteger(1);
        }
        while((High<1)||(High>5));
        cout<<"Min Wight: ";
        minWight=getDouble(1);
        cout<<"Max Wight: ";
        do
        {
            maxWight=getDouble(1);
            if ( maxWight <=  minWight )
            {
                cout << "the max wight dosen't make sense (*_*) !! .... reenter ."<<endl ;
            }
        }
        while(maxWight <= minWight );
        Truck* myTransport = new Truck(SN,Brand,Speed,Category,'T',minWight,maxWight,engineVolume,Lenght,High,mdate,x);
        transportList.add(myTransport);
    }
    else if(x==4)
    {
        cout<<"the number of Engines : ";
        numberOfEngine=getInteger(1);
        do
        {
            cout<<"Seats Number (between 20->200) :";
            Seats=getInteger(1);
        }
        while ((Seats<20)||(Seats>200));
        cout<<"Min Wight: ";
        minWight=getDouble(1);
        cout<<"Max Wight: ";
        do
        {
            maxWight=getDouble(1);
            if ( maxWight < ( minWight + (25*Seats) ))
            {
                cout << "the max wight dosen't make sense (*_*) !! .... reenter ." << endl << "it should be at least"<<( minWight + (25*Seats) )<<endl ;
            }
        }
        while(maxWight < ( minWight + (25*Seats)));
        CivilAerial*  myTransport = new CivilAerial(SN,Brand,Speed,Category,'C',minWight,maxWight,numberOfEngine,Lenght,Seats,mdate,x);
        transportList.add(myTransport);
    }
    else if(x==5)
    {
        cout<<"the number of Engines : ";
        numberOfEngine=getInteger(1);
        cout<<"Min Wight: ";
        minWight=getDouble(1);
        cout<<"Max Wight: ";
        do
        {
            maxWight=getDouble(1);
            if ( maxWight <=  minWight )
            {
                cout << "the max wight dosen't make sense (*_*) !! .... reenter ."<<endl ;
            }
        }
        while(maxWight <= minWight );
        TradeAerial* myTransport = new TradeAerial(SN,Brand,Speed,Category,'T',minWight,maxWight,numberOfEngine,Lenght,mdate,x);
        transportList.add(myTransport);
    }
}
//****************************************************************
void printNumber()
{
    int j=1,x,q;
    char from[20], to[20];
    Node<Journey>* myNode=journeyList.get_head();
    Transport *c;
    cout<<"Enter number of transport you want (SN) : ";
    q=getInteger(1);
    c=search_transport(q);
    if (c == NULL )
    {
        cout << "there is no such transport !" << endl ;
        return;
    }
    x=q;
    do
    {
        cout<<"From: ";
        cin>>from;
        cout<<"To: ";
        cin>>to;
        if (strcmp(to,from)==0)
        {
            cout << "the same place (*_*) Re Enter "<<endl;
        }
    }
    while(strcmp(to,from)==0);
    do
    {
        if( (myNode->data.getSN()==x) && (strcmp(from,myNode->data.getFrom())==0) && (strcmp(to,myNode->data.getTo())==0))
        {
            cout<<j<<"- Journey number: "<<myNode->data.getJourneyNumber()<<endl;
            j++;
        }
        myNode=myNode->next;
    }
    while(myNode!=NULL);
    if (j==1) cout << "there is no journey for this transport ... "<< endl ;
}
//****************************************************************
void calculatePassengerNumber()
{
    int x,sum=0;
    Node<Journey>* myNode=journeyList.get_head();
    cout<<"Enter Number of Transport (SN) : "<<endl;
    x=getInteger(1);
    Transport* c = search_transport(x);
    if(c == NULL)
    {
        cout<<"Not Found!!"<<endl;
        return;
    }
    int d1,d2,m1,m2,y1,y2;
    Date da1,da2,temp;
    bool error = false;
    do
    {
        if(error == true)
        {
            cout<<"Invalid Date!!"<<endl;
        }
        cout<<"Date of Bigning"<<endl;
        cout<<"Day: ";
        d1=getInteger(1);
        cout<<"Month: ";
        m1=getInteger(1);
        cout<<"Year: ";
        y1=getInteger(1);
        error = true;
    }
    while ( !(d1>=1&&d1<=30) || !(m1>=1&&m1<=12) || !(y1>=1950&&y1<=2050));
    da1 = Date(d1,m1,y1);
    error=false;
    do
    {
        if(error == true)
        {
            cout<<"Invalid Date!!"<<endl;
        }
        cout<<"Date of End"<<endl;
        cout<<"Day: ";
        d2=getInteger(1);
        cout<<"Month: ";
        m2=getInteger(1);
        cout<<"Year: ";
        y2=getInteger(1);
        error = true;
    }
    while ( !(d1>=1&&d1<=30) || !(m1>=1&&m1<=12) || !(y1>=1950&&y1<=2050));
    da2= Date(d2,m2,y2);
    if(da1>da2)
    {
        cout<<"you inversed the dates but i will consider it right (*_*) ..."<<endl;
        temp = da1;
        da1 = da2 ;
        da2 = temp ;
    }
    int i=1;
    do
    {
        if(myNode->data.getSN() == x && myNode->data.getdate() > da1 && myNode->data.getdate() < da2)
        {
            sum+=myNode->data.get_seatnum();
        }
        i++;
        myNode=myNode->next;
    }
    while(myNode!=NULL);
    if(sum == 0)
    {
        cout<<"No Journey for this Transport";
        return ;
    }
    cout << "the number of passengers is : "<<sum <<endl ;
}
//****************************************************************
int search_journey_for_add()
{
    Node<Journey>* temp;
    int x;
    cout<<"Enter number of Journey you want: ";
    x=getInteger(1);
    if (journeyList.getLenght() == 0 )
    {
        cout << "this is our first Journey ." << endl ;
        return x ;
    }
    if(x==journeyList.get_head()->data.getJourneyNumber())
    {
        cout<<"This Journey Number has taken!!"<<endl;
        return -1;
    }
    temp=journeyList.get_head()->next;
    while(temp!=NULL)
    {
        if(x==temp->data.getJourneyNumber())
        {
            cout<<"This Journey Number has taken!!"<<endl;
            return -1;
        }

        temp=temp->next;
    }
    return x ;
}
//****************************************************************
void newJourney()
{
    int w,journeyNumber,SN,se,secar,wight,wightcar,wightload,seatnum,day,month,year;
    Date date,tdate;
    Seat* seats;
    char transportType;
    double curWight,maxWight,minWight;
    Transport* c;
    int fullseat,q;
    char from[20], to[20];
    journeyNumber=search_journey_for_add();
    if(journeyNumber == -1)
    {
        cout<<"This Journey is already made ."<<endl;
        return;
    }
    cout<<"Enter number of transport you want (SN) : ";
    q=getInteger(1);
    c=search_transport(q);
    if (c==NULL)
    {
        cout<<"there is no such a transport"<<endl;
        return ;
    }
    if(c->getBker()==1)
        cout<<"This is a Personal car"<<endl;
    else if(c->getBker() ==2)
        cout<<"This is a Bus"<<endl;
    else if(c->getBker() ==3)
        cout<<"This is a Truck"<<endl;
    else if(c->getBker() ==4)
        cout<<"This is a Civil Airplane"<<endl;
    else if(c->getBker() ==5)
        cout<<"This is a Trade Airplane"<<endl;
    do
    {
        cout<<"From: ";
        cin>>from;
        cout<<"To: ";
        cin>>to;
        if (strcmp(to,from)==0)
        {
            cout << "the are the same place (*_*) " << endl << "reenter from --> to .."<<endl;
        }
    }
    while(strcmp(to,from)==0);
    bool error = false;
    do
    {
        if(error == true)
        {
            cout<<"Invalid Date!!"<<endl;
        }
        cout << "The date:"<<endl<<"Day: ";
        day=getInteger(1);
        cout<<"Month: ";
        month =getInteger(1);
        cout<<"Year: ";
        year =getInteger(1);
        date = Date(day,month,year);
        if(date<today || date==today)
        {
            cout<<"The Date Should start from tomorrow!!"<<endl;
            continue;
        }
        error = true;
    }
    while ( !(day>=1&&day<=30) || !(month>=1&&month<=12) || !(year>=1950&&year<=2050) || !(date > today) );
    SN=c->get_SN();
    if(!CheackAvilabilite(SN,date))return ;
    maxWight=c->get_maxWight();
    transportType=c->get_Type();
    minWight = c->get_minWight();
    if (c->getBker() == 1)                              //personal car
    {
        PersonalCar* p = (PersonalCar*) c;
        fullseat=p->get_sets();
        cout<<"This Car have "<<fullseat<<" Seats"<<endl ;
        do
        {
            cout << "how many seats you want : " <<endl;
            seatnum=getInteger(1);
            if (seatnum == 0)
            {
                cout << "this journey canceled because there is no passengers (*_*) "<<endl;
                return;
            }
            if (seatnum > fullseat)
            {
                cout <<"Total seats in this car is " << fullseat <<" !! "<<endl ;
            }
        }
        while(seatnum > fullseat);
        seats = new Seat[fullseat] ;
        for ( int i=0 ; i< fullseat ; i++ )
            seats[i] = Seat(false,i,0);
        for ( int i=0 ; i< seatnum; i++ )
        {
            do
            {
                cout << "Seat "<<i+1<<" :"<< endl ;
                secar =getInteger(1);
                cout<<"Wight :";
                wightcar=getDouble(0) ;
                if  ((secar > fullseat) || (wightcar > 25) )
                {
                    cout << "Invalid number please enter only in range (seats between 1->" << fullseat << " and wight leas then 26 )" << endl ;
                    i--;
                    continue;
                }
                if(seats[secar-1].getState())
                {
                    cout<<"This Seat is Taken,Choose Another!!"<<endl;
                    i--;
                    continue ;
                }
                else
                {
                    seats[secar-1] = Seat(true,secar,wightcar) ;
                }
            }
            while(false);
            curWight+=wightcar;
        }
        curWight+=minWight;

    }
    if (c->getBker() == 2 )                                // bus
    {
        Bus* p = (Bus*) c;
        do
        {
            fullseat=p->get_sets();
            cout <<"Total seats in this Bus is " << fullseat <<" !! "<<endl ;
            cout << "how many seats you want : " ;
            seatnum =getInteger(1);
            if (seatnum == 0)
            {
                cout << "this journey canceled because there is no passengers (*_*) "<<endl;
                return;
            }
            if (seatnum > fullseat)
            {
                cout <<"Total seats in this Bus is " << fullseat <<" !! "<<endl ;
            }
        }
        while(seatnum > fullseat);
        seats = new Seat[fullseat] ;
        for ( int i=0 ; i< seatnum ; i++ )
            seats[i] = Seat(false,i,0);
        for ( int i=0 ; i< seatnum ; i++ )
        {
            do
            {
                cout << "Seat "<<i+1<<" :"<< endl ;
                se =getInteger(1);
                cout<<"Wight :";
                wight=getDouble(0) ;
                if(se > fullseat || wight > 25 )
                {
                    cout << "Invalid number please enter only in range (seats between 1->" << fullseat << " and wight leas then 26 )" << endl ;
                    i--;
                    continue;
                }
                if(seats[se-1].getState())
                {
                    cout<<"This Seat is Taken "<<endl ;
                    i--;
                    continue ;

                }
                else  seats[se-1] = Seat(true,se,wight) ;
            }
            while(false);
            curWight+=wight;
        }
        curWight+=minWight;
        if(maxWight - curWight > 0)
        {
            cout<<"There are "<<(maxWight - curWight)<<" KG more space in Package"<<endl<<"you can add more goods for Trade"<<endl;
            cout<<"Enter How Much wight you want for treading or Enter Zero To continue"<<endl;
            cout<<"addition wight : ";
            do
            {
                w=curWight+getInteger(0);
                if (w>maxWight)
                    cout << "warning overload !! reenter .."<<endl;
            }
            while(w>maxWight);
            curWight = w;
        }
    }
    if (c->getBker() == 3)                   // truck
    {
        Truck* p = (Truck*) c ;
        do
        {
            cout << "Max Load is: "<<p->get_maxWight() - p->get_minWight() << endl ;
            cout << "wight of load: " ;
            wightload=getDouble(1) ;
            if ( p->Warning(wightload) )
            {
                cout << "Can't take This load! Max Load is: "<<p->get_maxWight() - p->get_minWight() << endl ;
            }
            curWight = wightload + minWight;
        }
        while ( p->Warning(wightload));
    }
    if (c->getBker() == 4)                               // civil aerial
    {
        CivilAerial* p = (CivilAerial*) c;
        do
        {
            fullseat = p->get_sets();
            cout <<"Total seats in this aerial plane is " <<fullseat<<" !! "<<endl ;
            cout << "how many seats you want : " ;
            seatnum=getInteger(1);
            if (seatnum == 0)
            {
                cout << "this journey canceled because there is no passengers (*_*) "<<endl;
                return;
            }
            if (seatnum > fullseat)
            {
                cout <<"Total seats in this plan is " <<fullseat<<" !! "<<endl ;
            }
        }
        while(seatnum > fullseat);
        seats = new Seat[fullseat] ;
        for( int i=0 ; i< seatnum ; i++ )
            seats[i] = Seat(false,i,0);
        for ( int i=0 ; i< seatnum ; i++ )
        {
            do
            {
                cout << "Seat "<<i+1<<" :"<< endl ;
                se=getInteger(1);
                cout<<"Wight :";
                wight =getDouble(0);
                if(seats[se-1].getState())
                {
                    cout<<"This Seat is Taken "<<endl; //, Would you like to cancel this person? (Y\N or another key)"<<endl;
                    i--;
                    continue;

                }
                if  (se > fullseat || wight > 25 )
                {
                    cout << "Invalid number please enter only in range (seats between 1->" <<fullseat<< " and wight leas then 26 )" << endl ;
                    i--;
                    continue;
                }
                else seats[se-1] = Seat(true,se,wight) ;
            }
            while(false);
            curWight+=wight;
        }
        curWight+=minWight;
        if(maxWight - curWight > 0)
        {
            cout<<"There are "<<(maxWight - curWight)<<" KG more space in Package"<<endl<<"you can add more goods for Trade"<<endl;
            cout<<"Enter How Much wight you want for treading or Enter Zero To continue"<<endl;
            cout<<"addition wight : ";
            do
            {
                w=curWight+getInteger(0);
                if (w>maxWight)
                    cout << "warning overload !! reenter .."<<endl;
            }
            while(w>maxWight);
            curWight = w;
        }
    }
    if ((c->getBker()) == 5 )                                      // trade aerial
    {
        TradeAerial* p = (TradeAerial*) c;
        cout << "Max Load is: "<<p->get_maxWight() - p->get_minWight() << endl ;
        do
        {
            cout << "wight of load: " ;
            wightload =getDouble(1);
            if ( p->Warning(wightload) )
            {
                cout << "Can't take This load! Max Load is: "<<p->get_maxWight() - p->get_minWight() << endl ;
            }
            curWight = wightload + minWight;
        }
        while (p->Warning(wightload));
    }
    Journey j(journeyNumber,SN,transportType, date,from,to,fullseat,seatnum,seats,minWight,curWight, maxWight) ;
    journeyList.add(j);
}
void todayFunction()
{
    cout<<"Today is:";
    today.Print();
    cout<<endl;
}
//****************************************************************
int main()
{
    design1();
    time_t current = time(0);
    tm *mytime= localtime(&current);
    today = Date(mytime->tm_mday,mytime->tm_mon +1,mytime->tm_year +1900);
    openFiles();
    char x;
    int q;

    do
    {
        todayFunction();
        cout<<"1- new Transport"<<endl;
        cout<<"2- new Journey"<<endl;
        cout<<"3- All Transport"<<endl;
        cout<<"4- All Journey"<<endl;
        cout<<"5- Search Transport By number"<<endl;
        cout<<"6- all Journey between two cites for transport"<<endl;
        cout<<"7- Calculate Passenger "<<endl;
        cout<<"8- Print all Journey for a Transport"<<endl;
        cout<<"9- TO EXITE"<<endl;
        x=getInteger(1);
        Transport* c;
        switch(x)
        {
        case 1:
            newTransport();
            system("PAUSE");
            system("cls");
            break;
        case 2:
            newJourney();
            system("PAUSE");
            system("cls");
            break;
        case 3:
            if(transportList.getLenght() == 0 )
            {
                cout << "the transport list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            transportListprint();
            system("PAUSE");
            system("cls");
            break;
        case 4:
            if(journeyList.getLenght() ==0 )
            {
                cout << "Journey list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            journeyListprint();
            system("PAUSE");
            system("cls");
            break;
        case 5:
            if(transportList.getLenght() ==0)
            {
                cout << "the transport list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            cout<<"Enter number of transport you want (SN) : ";
            q=getInteger(1);
            c=search_transport(q);
            if(c!=NULL)  c->print();
            system("PAUSE");
            system("cls");
            break;
        case 6:
            if(journeyList.getLenght() ==0)
            {
                cout << "the transport list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            printNumber();
            system("PAUSE");
            system("cls");
            break;
        case 7:
            if(journeyList.getLenght() ==0)
            {
                cout << "the Journey list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            calculatePassengerNumber();
            system("PAUSE");
            system("cls");
            break;
        case 8:
            if(journeyList.getLenght() ==0)
            {
                cout << "the journey list is empty ." << endl ;
                system("PAUSE");
                break ;
            }
            printinformation();
            system("PAUSE");
            system("cls");
            break;
        case 9:
            x=0;
            break;
        default:
            cout << "invalid input !!" << endl;
            system("cls");
            break;
        }
    }
    while(x!=0);
    finalFunctions();
    return 0;
}
//****************************************************************
