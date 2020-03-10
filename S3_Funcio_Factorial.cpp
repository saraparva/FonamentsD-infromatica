#include <iostream>
#include <fstream>
using namespace std;

float factorial(int num){
    int fact=1;
    while(num>0){
        fact*=num;
        num--;
    }
    return fact;
}

int main(){
    ifstream F("Fitxer.cpp");
    int num;
    while(F>>num){
        cout<<"El factorial del teu nombre es: "<<factorial(num)<<endl;
    }
}
