#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream F("Fitxer.cpp");
    long int fact=1;
    int n;
    cout<<"Introdueix un enter"<<endl;
    while(F>>n){
        fact*=n;
        n--;
    }
    cout<<"El factorial del teu nombre es: "<<prod<<endl;
}
