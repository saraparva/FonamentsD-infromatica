#include <iostream>
using namespace std;
int main(){
    int num,suma=0;
    cout<<"Introduce un numero positivo: ";
    cin>>num;
    while (num!=0){
        suma++;
        num/=10;
    }
    cout<<"El numero de cifras es: "<<suma<<endl;
}
