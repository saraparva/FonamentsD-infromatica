#include <iostream>
#include <fstream>
using namespace std;

bool positivo (int n){
    if (n>0){
        return true;}
    else{
        return false;}
}

int suma_divisores(int n){
    int i,suma=0;
    for(i=1;i<n;i++){
        if (n%i==0){
            suma+=i;
        }
    }
    return suma;
}

int funcion(int n){
    return 2*n+1;
}

int main(){
    ifstream fin("prueba.txt");
    int n, comptnum=0, comptneg=0;
    while(fin>>n){
        comptnum++;
        if(positivo(n)){
            cout<<"La suma de divisores es: "<<suma_divisores(n)<<endl;
            cout<<"2*n+1 es igual a: "<<funcion(n)<<endl;
        }
        else{
            comptneg++;
        }
    }
    cout<<"El porcentage de numeros negativos introducidos respecto el numero total de numeros es: "<<(float(comptneg)/comptnum)*100<<endl;
}
