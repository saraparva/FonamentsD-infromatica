#include <iostream>
using namespace std;
int main(){
    int g,m,s;
    float r;
    cout<<"Introduiu un angle en graus, minuts i segons (graus minuts segons)"<<endl;
    cin>>g>>m>>s;
    //1g=3600s
    s/=3600;
    m/=60;
    g+=m+s;
    //360g=2*pi rad
    r=float(g*2)/360;
    cout<<"El teu angle en radians es: "<<r<<"*PI radians"<<endl;
}
