#include <iostream>
using namespace std;
int main(){
    int a,b;
    bool condicio1,condicio2,condicio3;
    cout<<"Introdueix dos nombres enters: ";
    cin>>a>>b;
    condicio1=(-255<a && a!=0 && a<255 && -255<b && b!=0 && b<255);
    condicio2=(a%2!=0 && b%2==0);
    condicio3=(b=='A' || b=='B' || b=='C' || b=='D' || b=='E' || b=='F' || b=='G' || b=='H' || b=='I' || b=='J' || b=='K' || b=='L' || b=='M' || b=='N' || b=='O' || b=='P' || b=='Q' || b=='R' || b=='S' || b=='T' || b=='U' || b=='V' || b=='W' || b=='X' || b=='Y' || b=='Z');
    if(condicio1){
        if(condicio2){
            cout<<"Es compleix la primera condicio."<<endl;
            if((a-b)>=2){
                cout<<"El residu de dividir el primer nombre entre el segon es: "<<a%b<<endl;
            }
            else{if(a==b || (a-b)==1 || (b-a)==1){
                    cout<<"Son iguals."<<endl;}
                else{
                    cout<<"La diviso sencera del segon entre el primer es: "<<b/a<<endl;}
            }
        }
        else{
            cout<<"No es compleix la primera condicio."<<endl;}
        if(a%10==0 && a%3==0){
            a=-a;}
        if(condicio3){
            b+=a;}
        cout<<"El resultat de multiplicar els valors actuals dels dos nombres es: "<<a*b<<endl;
    }
    else{
        cout<<"Els nombres enters introduis no son valids, estan fora del rang permes."<<endl;
    }
}
