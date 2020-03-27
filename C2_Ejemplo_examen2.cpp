#include <iostream>
#include <fstream>
using namespace std;

int factorial(long int n){
    int i,fact=1;
    for(i=n;i>0;i--){
        fact*=i;
    }
    return fact;
}

int num_xifres(int n){
    int xifres=0;
    while(n!=0){
        n/=10;
        xifres++;
    }
    return xifres;
}

bool es_positiu(int n){
    if (n>0){
        return true; }
    else{ return false; }
}

int main(){
    int num;
    ifstream fit("Entrada1.txt");
    while (fit>>num){
        if (es_positiu(num)){
            cout<<num<<" es un enter positiu."<<endl;
            cout<<"El faltorial de "<<num<<" es: "<<factorial(num)<<endl;
            cout<<"El nombre de xifres que te el nombre "<<num<<" es: "<<num_xifres(num)<<endl;
        }
        else{
            cout<<num<<" es un nombre enter negatiu."<<endl;
        }
    }
}
