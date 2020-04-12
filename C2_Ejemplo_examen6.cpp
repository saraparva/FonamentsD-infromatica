#include <iostream>
#include <fstream>
using namespace std;

bool es_lletra(char caracter){
    if ((caracter>='A' && caracter<='Z')||(caracter>='a' && caracter<='z')){
        return true;}
    else{
        return false;}
}

bool es_vocal(char caracter){
    bool vocal;
    switch (caracter){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        vocal=true;
        break;
    }
    return vocal;
}

void comptadors(char caracter, int &comptv, int &comptc, int &comptn, int &comptl){
    if (es_lletra(caracter)){
        comptl++;
        if (es_vocal(caracter)){
            comptv++;
        }
        else{
            comptc++;
        }
    }
    else{
        comptn++;
    }
}

int main(){
    char caracter;
    int comptv=0, comptc=0, comptn=0, comptl=0, comptch=0;
    ifstream texto("ElQuijote.txt");
    while(texto>>caracter){
        comptch++;
        comptadors(caracter,comptv,comptc,comptn,comptl);
    }
    cout<<"La quantitat de vocals es: "<<comptv<<endl;
    cout<<"La cuantitat de consonants es: "<<comptc<<endl;
    cout<<"El percentatge de caracters que no son lletres es: "<<(float(comptn)/comptch)*100<<'%'<<endl;
    cout<<"El percentatge de lletres que son vocals es: "<<(float(comptv)/comptl)*100<<'%'<<endl;
}
