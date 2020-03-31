#include <iostream>
#include <fstream>
using namespace std;

void separar_data(int data, int &dia, int &mes, int &any){
    any=data%1000;
    mes=(data/1000)%100;
    dia=data/1000000;
}

float retornXdata(int data,float despeses){
    int dia, mes, any, consum, retorn=0,euros;
    separar_data(data,dia,mes,any);
    if (mes%2!=0){
        if (dia<=15){
            retorn+=0.1;}
        else{
            retorn+=0.05;}}
    else{
        retorn+=0.15;}
    if (mes>=6 && mes<=9){
        retorn+=0.05;}
    euros=despeses*retorn;
}

float retornXmes(int despesesMes){
    int i,euros=0;
    for(i=1;i<despeses/100;i++){
        euros+=despesesMes*0.5*i;
    }
    return euros;
}

int main(){
    ifstream fi("despeses.txt");
    int data,dia, mes, any;
    float despeses,euros=0 despesesMes=0;
    while (fi>>data>>despeses){
        despesesMes+=despeses;
        euros+=retornXdata(data,despeses);
    }
    euros+=retornMes(despesesMes);
    cout<<"Euros a tornar = "<<euros<<" €"<<endl;
}
