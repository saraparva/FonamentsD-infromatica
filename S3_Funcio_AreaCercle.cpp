#include <iostream>
#include <math.h>
const float pi=3.14;
using namespace std;

float distancia(float x1,float y1,float x2,float y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

float areaCercle(float r){
    return pi*r*r;
}

int main(){
    float a,b,x,y,radi;
    cout<<"Introdueix les coordenades del centre del cercle: ";
    cin>>a>>b;
    cout<<"Introdueix les coordenades d'un punt de la circumferencia: ";
    cin>>x>>y;
    radi=distancia(a,x,b,y);
    cout<<"L'area del cercle es: "<<areaCercle(radi)<<endl;
}
