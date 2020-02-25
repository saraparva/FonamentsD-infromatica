#include <iostream>
using namespace std;
const float TB=0.45;
int main(){
    int num,prefix,horai,hi,mi,horaf,hf,mf,minuts;
    float preu;
    cout<<"Indica l'hora d'inici i de finalitzaci— (hhmm) i el numero al que vols trucar:"<<endl;
    cin>>horai>>horaf>>num;
    hi=horai/100; mi=horai%100;
    hf=horaf/100; mf=horaf%100;
    prefix=num/100000;
    if(0<=hi<=23 && 0<=hf<=23 && 0<=mi<=59 && 0<=mf<=59 && prefix<1000){
        mi+=hi*60;
        mf+=hf*60;
        if(mi<mf){
            minuts=mf-mi;
            if(prefix<10){preu=minuts*TB;}
            else{if(prefix<100){preu=minuts*1.5*TB;}
                else{preu=minuts*1.8*TB;}
            }
            if(mi<=359){preu*=0.5;}
            cout<<"La trucada de "<<minuts<<" minuts te un cost de "<<preu<<" euros."<<endl;
        }
        else{cout<<"ERROR-Entrada incorrecta."<<endl;}
    }
    else{cout<<"ERROR-Entrada incorrecta."<<endl;}
}
