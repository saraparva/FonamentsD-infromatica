#include <iostream>
using namespace std;
int main(){
	int numero,x, h,m,s;
	cout<<"Introdueix hora en format HHMMSS i una quantitat en segons"<<endl;
	cin>>numero>>x;
	s=numero%100; m=numero/100%100; h=numero/10000;
	if (s>=0 && s<60 && m>= 0 && m<60 && h>=0 && h<24 && x>=0 && x<60){
        s+=x;
        if(s>=60){
            s%=60;
		 	m++;
		 	if(m>=60){
                m%=60; h++;
            }
        }
		if(h>=12){
            h%=12;}
        cout<< "sortida: "<<h<<":"<<m<<":"<<s;
	 }
	 else {
        cout << "Entrada erronea"<<endl;}
}
