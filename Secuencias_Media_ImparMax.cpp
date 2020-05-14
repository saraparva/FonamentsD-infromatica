#include <iostream>
using namespace std;
int main(){
    int num, imparMax=0, suma=0, compt=0;
    cout<<"Introdueix una sequencia de nombres acabada en zero."<<endl;
    cin>>num;
    if (num!=0){
        while(num!=0){
            compt++;
            suma+=num;
            if (num%2!=0){
                if (num>imparMax){
                    imparMax=num;
                }
            }
            cin>>num;
        }
        cout<<"La mitjana de tots els nombres es: "<<float(suma)/compt<<endl;
        if (imparMax==0){
            cout<<"No hi ha cap nombre impar a la sequencia."<<endl;
        }
        else{
            cout<<"El nombre impar maxim es: "<<imparMax<<endl;
        }
    }
    else{
        cout<<"No hi ha cap sequencia."<<endl;
    }
}
