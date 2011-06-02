#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

/////////////////////////////
////////Class Vehicle///////
///////////////////////////
class vehicle
{
      public:
             //variables
             int max_seats[3];
             string name;
             //Constructors
             vehicle()
             {
                 max_seats[0]=-1;
                 max_seats[1]=-1;
                 max_seats[2]=-1;
                 name="VEHICLE";
             };
             vehicle(int a,int b, int c,string n)
             {
                 max_seats[0]=a;
                 max_seats[1]=b;
                 max_seats[2]=c;
                 name =n;
             };
             //funcions 
};

/////////////////////////////
////////Class Route///////
///////////////////////////
class route: public vehicle
{
      public:
             //variables
             string terminal;
             string destination;
             vehicle ve;
             int seat_availability[3];
       
             //constructors
             route()
             {terminal="";destination="";seat_availability[0]=0;seat_availability[1]=0;seat_availability[2]=0;}
             route(string,string,vehicle);

             //functions             
};
//////////////////////////////
/////Route///////////////////
//function declarrations////
///////////////////////////
route::route(string t, string d,vehicle v)
{
                    
       terminal=t;
       destination=d;
       ve=v;
       seat_availability[0]=v.max_seats[0];
       seat_availability[1]=v.max_seats[1];
       seat_availability[2]=v.max_seats[2];
}



///////////////////////////////
///////Office/////////////////
/////////////////////////////
class office: public route
{
      public:
             //variables
             route routes[100];
             vehicle vehicles[3];
             int routes_number;

             //functions
             void exportdata();
             void menu();
             void handle_choice(int);
             void printstatus(route);
             void printroutes(route*,int);             
             
             int book_seat(route*,int);
             int cancel_seat(route*,int);
             
             void availability();

};

//////////////////////////////
/////////Office//////////////
///Function Declaration/////
///////////////////////////
void office::menu()
{
     int choice=0;
         system("cls");
         cout<<"Welcome to \"GEID\" travel Agency"<<endl;
         cout<<"0.Exit"<<endl;
         cout<<"1.Print Status"<<endl;
         cout<<"2.Export status to file"<<endl;
         cout<<"3.Book a seat"<<endl;
         cout<<"4.Cancel a seat"<<endl;
         cout<<"5.Check Availability"<<endl;
         cout<<"Select your choice :";         
         cin>>choice;
         handle_choice(choice);
}
void office::handle_choice(int choice)
{
     string temp_string;
     int temp_int, temp_int2;
     char temp_char;
     system("cls");
     switch(choice)
     {
           case 0:
                //////////////////
                //exit program///
                ////////////////
                cout<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<"---------Thanks for using---------"<<endl;
                cout<<"----------------------------------"<<endl<<endl;
                system("PAUSE");
                exit(0);
                break;
           case 1:
                //////////////////
                //Print Status///
                ////////////////
                printroutes(routes,routes_number);
                cout<<"please choose route: ";
                cin>>temp_int;
                while(temp_int<0 || temp_int>routes_number-1)
                {
                      cout<<"Wrong choice\n";
                      cout<<"please choose route: ";
                      cin>>temp_int;
                }
                printstatus(routes[temp_int]);
                break;
           case 2:
                //////////////////
                //Export Status//
                ////////////////
                exportdata();
                break;
           case 3:
                //////////////////
                ///Book a seat///
                ////////////////
                printroutes(routes,routes_number);
                cout<<"Which route you want to book a seat: ";
                cin>>temp_int;
                while(temp_int<0 || temp_int>routes_number-1)
                {
                      cout<<"Wrong choice\n";
                      cout<<"please choose route: ";
                      cin>>temp_int;
                }                
                printstatus(routes[temp_int]);
                (routes[temp_int].ve.max_seats[0]!=0?temp_char='A':temp_char='B');
                do{
                   cout<<"1."<<(char)temp_char<<endl<<"2."<<char(temp_char+1)<<endl;
                   cout<<"Which category:";
                   cin>>temp_int2;
                }while((int)temp_int2<0||(int)temp_int2>2);// cout<<"Wrong Choice\n");

                book_seat(&routes[temp_int],temp_int2-1);
                break;
           case 4:
                //////////////////
                //Cancel a seat//
                ////////////////
                printroutes(routes,routes_number);
                cout<<"In which route you want to cancel a seat: ";
                cin>>temp_int;
                printstatus(routes[temp_int]);
                (routes[temp_int].ve.max_seats[0]!=0?temp_char='A':temp_char='B');
                do{
                   cout<<"1."<<(char)temp_char<<endl<<"2."<<char(temp_char+1)<<endl;
                   cout<<"Which category:";
                   cin>>temp_int2;
                }while(temp_int2<0||temp_int>2);// cout<<"Wrong Choice\n");
                cancel_seat(&routes[temp_int],temp_int2-1);
                break;
           case 5:
                ///////////////////////
                //Check Availability//
                /////////////////////
                availability();
     }
     system("PAUSE");
     menu();
}

void office::printstatus(route r)
{
     int total=r.ve.max_seats[0]+r.ve.max_seats[1]+r.ve.max_seats[2];
     int available =r.seat_availability[0]+r.seat_availability[1]+r.seat_availability[2];
     int pcat;
     char cat;
     system("cls");
     r.ve.name=="FERRY"?cat='B':cat='A';
     r.ve.name=="FERRY"?pcat=1:pcat=0;
          
     cout<<"======================== "<< r.ve.name<<" ========================"<<endl;
     cout<<"ROUTE               "<<r.terminal<<" - "<<r.destination<<endl;
     cout<<"TOTAL SEATS:        "<< total<<endl;
     cout<<"RESERVED SEATS:     "<< total-available<<endl;
     cout<<"AVAILABLE SEATS:    "<<available<<endl;
     cout<<"---------------------- RESERVED -----------------------"<<endl;
     cout<<"               "<< cat <<" CLASS     "<< (char)(cat+1) <<" CLASS"<<endl;
     cout<<"                  "<<r.ve.max_seats[pcat]-r.seat_availability[pcat]<<"           "<<r.ve.max_seats[pcat+1]-r.seat_availability[pcat+1]<<endl;
     cout<<"---------------------- AVAILABLE ----------------------"<<endl;
     cout<<"               "<< cat <<" CLASS     "<< (char)(cat+1) <<" CLASS"<<endl;
     cout<<"                  "<<r.seat_availability[pcat]<<"           "<<r.seat_availability[pcat+1]<<endl;     
     cout<<"======================================================="<<endl;
}

void office::printroutes(route *r,int size)
{
     cout<<"-------ROUTES AVAILABLE-------"<<endl;
     cout<<0<<". "<<r[0].ve.name<<": "<<r[0].terminal<<"-"<<r[0].destination<<endl;
     for(int i=1;i<size;i++)
     {
             if(r[i-1].ve.name!=r[i].ve.name)
             cout<<"------------------------------"<<endl;
             cout<<i<<". "<<r[i].ve.name<<": "<<r[i].terminal<<"-"<<r[i].destination<<endl;
     }
}
void office::exportdata()
{
     route r;
     ofstream file;
	file.open("kratiseis.txt");	
	
     for(int i =0;i<routes_number;i++)
     {
             r=routes[i];
     int total=r.ve.max_seats[0]+r.ve.max_seats[1]+r.ve.max_seats[2];
     int available =r.seat_availability[0]+r.seat_availability[1]+r.seat_availability[2];
     int pcat;
     char cat;
     r.ve.name=="FERRY"?cat='B':cat='A';
     r.ve.name=="FERRY"?pcat=1:pcat=0;
          
     file<<"======================== "<< r.ve.name<<" ========================"<<endl;
     file<<"ROUTE               "<<r.terminal<<" - "<<r.destination<<endl;
     file<<"TOTAL SEATS:        "<< total<<endl;
     file<<"RESERVED SEATS:     "<< total-available<<endl;
     file<<"AVAILABLE SEATS:    "<<available<<endl;
     file<<"---------------------- RESERVED -----------------------"<<endl;
     file<<"               "<< cat <<" CLASS     "<< (char)(cat+1) <<" CLASS"<<endl;
     file<<"                  "<<r.ve.max_seats[pcat]-r.seat_availability[pcat]<<"           "<<r.ve.max_seats[pcat+1]-r.seat_availability[pcat+1]<<endl;
     file<<"---------------------- AVAILABLE ----------------------"<<endl;
     file<<"               "<< cat <<" CLASS     "<< (char)(cat+1) <<" CLASS"<<endl;
     file<<"                  "<<r.seat_availability[pcat]<<"           "<<r.seat_availability[pcat+1]<<endl;     
     file<<"======================================================="<<endl;
     file<<endl;
     }
     file.close();
}

int office:: book_seat(route *r, int cat)
{
    if (r->ve.name=="FERRY")
       cat++;
    cout<<"How many seats you want to book: ";
    int temp;
    cin>>temp;
    if(r->seat_availability[cat] - temp >=0)
    {
        r->seat_availability[cat]-=temp;
        return 0;//there are seats available
    }
    else
    {
        cout<<"Sorry but there are not so many seats available"<<endl;
        cout<<"There are only "<<r->seat_availability[cat]<<endl;
        return 1;//no seats available
    }  
}

int office:: cancel_seat(route *r, int cat)
{
    cout<<"How many seats you want to cancel: ";
    int temp;
    cin>>temp;
    if(r->seat_availability[cat]+temp<=r->ve.max_seats[cat])
    {
        r->seat_availability[cat]+=temp;

        return 0;//there are seats available
    }
    else
    {
        cout<<"Sorry but you cannot cancel so many seats"<<endl;
        cout<<"There are only "<<r->ve.max_seats[cat]-r->seat_availability[cat]<<" reserved"<<endl;
        return 1;//no seats available
    }
}

void office::availability()
{
    /*
      if no seats then return 0
      else return the remaining seats
    */
    int temp_int;
      cout<<"  ->1. Check by Route"<<endl;
      cout<<"  ->2. Check by Category"<<endl;
      cout<<"Select one: ";
      cin>> temp_int;
                
      while(temp_int<1 || temp_int>2)
      {
            cout<<"Wrong selection. Please select again: ";
            cin>>temp_int;
      }
                
      if(temp_int==1)
      {

          printroutes(routes,routes_number);
          cout<<"Please select a route: ";
          cin>>temp_int;
          route r = routes[temp_int];
          int total=r.ve.max_seats[0]+r.ve.max_seats[1]+r.ve.max_seats[2];
          int available =r.seat_availability[0]+r.seat_availability[1]+r.seat_availability[2];
          int remaining = total-available;
          if (available==0)
             cout<<"There are no seats available"<<endl;
          else
             cout<<"There are "<<available<<" seats available"<<endl; 
      }
      else if(temp_int==2)
      {
           cout<<"1. A\n2. B\n3. C"<<endl;
           cout<<"Give me category: ";
           cin>>temp_int;
           
           cout<<"Available Routes for "<<(char)(temp_int+ 64)<<" Class"<<endl;
           for(int i =0;i<routes_number;i++)
              if(routes[i].seat_availability[temp_int-1]>0)
              {
                 cout<<"There are "<<routes[i].seat_availability[temp_int-1]<<" seats for: ";
                 cout<<routes[i].ve.name<<", "<<routes[i].terminal<<" - "<<routes[i].destination<<endl;
              }                      
      }
}
