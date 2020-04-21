#include <iostream>
#include <fstream>
using namespace std;

void estada_parking (int arribada, int sortida, int &h, int &m, float &preu);

int main(){
    int arribada, sortida, hores, minuts,i=1,cocheMin,cocheMax,pagoMin,pagoMax=0;
    float preu,recaudacio=0;
    string mot_a,mot_s;
    ifstream fin("cotxes.txt");
    ofstream fot("parking.txt");
    while(fin>>arribada>>mot_a>>sortida>>mot_s){
        preu=0;
        if(mot_a=="pm"){
            arribada+=1200;
        }
        if(mot_s=="pm"){
            sortida+=1200;
        }
        estada_parking(arribada,sortida,hores,minuts,preu);
        fot<<"Coche "<<i<<" - Tiempo de parking "<<hores<<" horas y "<<minuts<<" minutos, a pagar: "<<preu<<" euros."<<endl;
        i++;
        recaudacio+=preu;
    }
    fot<<"La recaudacion del dia, de "<<i<<" coches, ha sido: "<<recaudacio<<" euros."<<endl;
}

void estada_parking (int arribada, int sortida, int &h, int &m, float &preu){
    int temps_estada,temps,H;
    temps_estada=sortida-arribada;
    m=temps_estada%100;
    h=temps_estada/100;
    temps=h*60+m;
    if (temps>=30){
        preu+=30*0.1;
        temps-=30;
    }
    else{
        preu+=temps*0.1;
    }
    preu+=temps*0.05;
    preu-=h*0.5;
}
