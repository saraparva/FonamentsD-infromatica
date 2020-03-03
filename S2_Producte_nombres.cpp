#include <iostream>
using namespace std;
const int N=5;
int main(){
    int num,prod=1,i;
    cout<<"Programa que demana "<<N<<" numeros reals i calcula el seu productes "<<endl<<endl;
    for (i=0;i<N;i++){
        cout<<"Introdueix un nombre real: ";
        cin>>num;
        prod*=num;
    }
    cout<<endl<<"El producte dels nombres donats es: "<<prod<<endl;
}
