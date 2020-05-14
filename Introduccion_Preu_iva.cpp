#include <iostream>
using namespace std;
int main (){
    double preu,unitats, total, iva;
    cout<<"Unitats desitjades: ";
    cin>>unitats;
    cout<<"Preu unitari: ";
    cin>>preu;
    preu+=(preu*0.16);
    total=unitats*preu;
    cout << "Total a pagar (preu+iva): "<<total<<"euros."<< endl;
}
