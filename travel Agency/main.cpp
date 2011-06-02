#include <cstdlib>
#include <iostream>

#include "office.h"


using namespace std;

int main(int argc, char *argv[])
{
    office geid;
    
    
    vehicle train(6,12,0,"TRAIN");
    vehicle ferry(0,10,24,"FERRY");
    vehicle plane(4,16,0,"PLANE");

    geid.vehicles[0]=train;
    geid.vehicles[1]=ferry;
    geid.vehicles[2]=plane;
    

    
    geid.routes[0]= route("Patras","Athens",train);
    geid.routes[1]= route("Patras","Pyrgos",train);
    geid.routes[2]= route("Athens","Thessaloniki",train);
    geid.routes[3]= route("Athens","Lianokladi",train);
    geid.routes[4]= route("Athens","Larisa",train);
    
    geid.routes[5]= route("Patras","Ancona",ferry);
    geid.routes[6]= route("Patras","Venice",ferry);
    geid.routes[7]= route("Patras","Brindisi",ferry);
    
    geid.routes[8]= route("Athens","Thessaloniki",plane);
    geid.routes[9]= route("Athens","Milan",plane);
    geid.routes[10]= route("Athens","Frakfourt",plane);
    geid.routes[11]= route("Athens","New York",plane);
    geid.routes_number=12;

    geid.menu();    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
