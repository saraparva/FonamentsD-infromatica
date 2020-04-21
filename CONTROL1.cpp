#include <iostream>
using namespace std;
int main(){
    int a,b;
    bool condicio1,condicio2,condicio3;
    cout<<"Introdueix dos nombres enters: ";
    cin>>a>>b;
    condicio=(-255<a && a!=0 && a<255 && -255<b && b!=0 && b<255);
    condicio1=(a%2!=0 && b%2==0);
    condicio2=(b>='A' && b<='Z');
    if(condicio){
        if(condicio1){
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
        if(condicio2){
            b+=a;}
        cout<<"El resultat de multiplicar els valors actuals dels dos nombres es: "<<a*b<<endl;
    }
    else{
        cout<<"Els nombres enters introduis no son valids, estan fora del rang permes."<<endl;
    }
}
