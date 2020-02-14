#include <iostream>
using namespace std;
int main(){
    int segundos,n,s,m,h,d;
    cout<<"Introduiu una quantitat de segons: ";
    cin>>n;
    segundos=n;
    s=n%60;
    n/=60;
    m=n%60;
    n/=60;
    h=n%24;
    d=n/24;
    cout<<segundos<<" segons son "<<d<<"dies, "<<h<<" hores, "<<m<<" minuts i "<<s<<" segons."<<endl;

}
