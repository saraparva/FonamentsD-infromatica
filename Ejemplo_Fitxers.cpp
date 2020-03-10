//Programa que llegeix un fitxer d'una llista de nombres i escriu quantes vegades surt el 33
//Necesitem un archiu de text anomenat facil.txt
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream llista("facil.txt");
    int num,suma=0;
    while(llista>>num){
        if(num==33){
            suma++;
        }
    }
    cout<<"A la llista apareix el nombre 33 "<<suma<<" vegades."<<endl;
}
