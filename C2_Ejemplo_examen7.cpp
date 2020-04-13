#include <iostream>
#include <fstream>
using namespace std;

void premi(int num1, int num2, int num3, int &compt20, int &compt50){
    bool xifres;
    int n1,n2,n3;
    xifres=(num1>=100 && num1<1000 && num2>=100 && num2<1000 && num3>=100 && num3<1000);
    if(xifres){
        if(num1==num2 && num2==num3){
            n3=num1%10;
            n2=(num1/10)%10;
            n1=num1/100;
            if(n2>n1 && n2>n3){
                compt50++;
            }
            if(n2<n1 || n2<n3){
                compt20++;
            }
        }
    }
}

int main(){
    int num1, num2, num3, comptn=0, compt20=0, compt50=0;
    ifstream fitxer("Mod5.txt");
    while(fitxer>>num1>>num2>>num3){
        comptn++;
        premi(num1,num2,num3,compt20,compt50);
    }
    cout<<"Premis de 20 euros: "<<(float(compt20)/comptn)*100<<'%'<<endl;
    cout<<"Premis de 50 euros: "<<(float(compt50)/comptn)*100<<'%'<<endl;
}
