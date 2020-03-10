#include <iostream>
#include <math.h>
using namespace std;
double distancia(double x1,double y1,double x2,double y2,double z1,double z2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main(){
    double x1,y1,z1,x2,y2,z2;
    cout<<"Entra el primer punt de dues components reals: ";
    cin>>x1>>y1>>z1;
    cout<<"Entra el segon punt de dues components reals: ";
    cin>>x2>>y2>>z2;
    cout<<"La distancia entre el primer i el segon punt es "<< distancia(x1,y1,x2,y2,z1,z2) << endl;

}
