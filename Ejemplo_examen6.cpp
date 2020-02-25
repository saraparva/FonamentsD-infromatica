#include <iostream>
using namespace std;
int main(){
    float a,b,suma;
    int producte;
    bool condicio;
    cout<<"Escriu dos valors numerics reals.";
    cin>>a>>b;
    condicio=(-12.0<a && a<59.8 && 49.2<b && b<98.5);
    if (condicio){
        //PART 1
        producte=a*b;
        if(producte%2==0){
            cout<<"La part real del producte dels dos nombres es par."<<endl;}
        else{
            cout<<"La part real del producte dels dos nombres es impar."<<endl;}
        //PART 2
        suma=a+b;
        if(suma<0){
            cout<<"La suma dels dos nombres es negatiu."<<endl;}
        else{
            if(suma>0){
                cout<<"La suma dels dos nombres es positiu."<<endl;}
            else{
                cout<<"La suma dels dos nombres es zero."<<endl;}
        }
    }
    else{
        cout<<"Valors erronis"<<endl;}
}
