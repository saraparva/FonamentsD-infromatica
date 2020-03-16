#include <iostream>
#include <math.h>
using namespace std;

float distancia(float x1,float y1,float x2,float y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    float x1,x2,y1,y2,X1,X2,Y1,Y2,distanciap,DISTANCIA=0.0;
    while(x1==0.0 & y1==0.0){
        cin>>x1>>y1;
        cin>>x2>>y2;
        distanciap=distancia(x1,y1,x2,y2);
        if (distanciap>DISTANCIA){
            distanciap=DISTANCIA;
            X1=x1;X2=x2;Y1=y1;Y2=y2;
        }
    }
    cout<<"La distancia mes gran es troba entre els punts: ("<<X1<<','<<Y1<<") i ("<<X2<<','<<Y2<<") i es: "<<DISTANCIA<<endl;
}
