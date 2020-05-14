#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int num,numInvertido=0;
    cout<<"Escriu un numero: ";
    cin>>num;
    while(num!=0){
        numInvertido=numInvertido*10+num%10;
        num/=10;
    }
    cout<<"El teu numero al reves es: "<<numInvertido<<endl;
}
