#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int num,numc,cifras=0,i,potencia,suma=0,cifra;
    cout<<"Escriu un numero: ";
    cin>>num;
    numc=num;
    while(numc!=0){
        cifras++;
        numc/=10;
    }
    cifras--;
    for(i=cifras;i>=0;i--){
        cifra=num%10;
        potencia=pow(10,i);
        cifra*=potencia;
        suma+=cifra;
        num/=10;
    }
    cout<<"El teu numero al reves es: "<<suma<<endl;
}
