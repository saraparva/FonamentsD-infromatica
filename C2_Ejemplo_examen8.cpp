#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

long int concatenacio (long int n1, long int n2){
    int suma_xifres=0,nombre_xifres=0,num2;
    num2=n2;
    while (n1>0){
        suma_xifres+=n1%10;
        n1/=10;
    }
    while(num2>0){
        nombre_xifres++;
        num2/=10;
    }
    return suma_xifres*(pow(10,nombre_xifres))+n2;
}

int num_xifres(long int n){
    int n_xifres=0;
    while(n>0){
        n_xifres++;
        n/=10;
    }
    return n_xifres;
}

int main(){
    long int n1,n2;
    int compt7=0, comptp=0;
    ifstream fitxer("Mod4.txt");
    while(fitxer>>n1>>n2){
        comptp++;
        if(num_xifres(concatenacio(n1,n2))==7){
            compt7++;
        }
    }
    cout<<(float(compt7)/comptp)*100<<'%'<<endl;
}
