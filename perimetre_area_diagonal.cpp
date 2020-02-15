#include <iostream>
#include <math.h>
using namespace std;
const float PI=3.14159;
int main(){
    float costat,diagonal;
    cout<<"Introduiu el valor del costat: ";
    cin>>costat;
    diagonal=costat*sqrt(2);
    cout<<"El perimetre del quadrat es: "<<4*costat<<endl;
    cout<<"L'area del quadrat es: "<<costat*costat<<endl;
    cout<<"La longitud de la diagonal del quadrat es: "<<diagonal<<endl;
}
