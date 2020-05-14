#include <iostream>
using namespace std;
int main(){
    float preu,suma=0.0;
    cout<<"Introdueix el preu dels productes que has comprat:"<<endl;
    cout<<"Per terminar la llista posa un zero."<<endl;
    while (preu!=0){
        cin>>preu;
        suma+=preu;
    }
    cout<<"El cost total de tots els productes es: "<<suma<<endl;
}
