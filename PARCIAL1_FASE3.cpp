#include <iostream>
#include <fstream>
using namespace std;

int invertir (int num);
void Seleccionador (int num, bool &seleccionat, int &codi);

int main(){
    int DNI, codi, alumnes=0, alumnes_seleccionats=0;
    bool seleccionat;
    cin>>DNI;
    Seleccionador(DNI, seleccionat, codi);
    if (seleccionat){
        cout<<DNI<<' '<<codi<<endl;
    }
}

int invertir (int num){
    int n=0;
    while(num!=0){
       n=n*10+(num%10);
       num/=10;
    }
    return n;
}

void Seleccionador (int DNI, bool &seleccionat, int &codi){
    int num, n, m, compt_impar=0;
    bool par;
    num=DNI;
    par=(n%2==0);
    while (num>0){
        n=num%10;
        if(!par){compt_impar++;}
        num/=10;
    }
    if(compt_impar>=2){seleccionat=true;}
    else{seleccionat=false;}

    compt_impar=0;
    while(DNI>0){
        n=DNI%10;
        if(n%2!=0){compt_impar++;}
        if(compt_impar<3){DNI/=10;}
        else{
            m=DNI;
            DNI=0;
        }
    }
    codi=invertir(m);
}
