#include <iostream>
using namespace std;
const float SS=0.18;
int main(){
    int fills,soub;
    float IRPF,souf;
    char categoria;
    cout<<"Indica la lletra que identifica la categoria de l'empleat i el nombre de fills que te: ";
    cin>>categoria>>fills;
    if ((categoria=='O'||categoria=='C'||categoria=='E'||categoria=='G')&&(0<fills && fills<15)){
        if (categoria=='O'){soub=1050;}
        else{if(categoria=='C'){soub=1350;}
            else{if(categoria=='E'){soub=2410;}
                else{soub=1350;}
        }}
        if(fills==0 || fills==1){IRPF=0.18;}
        else{if(fills==2){IRPF=0.12;}
            else{IRPF=0.08;}
        }
        souf=soub-(soub*SS)-(soub*IRPF);
        cout<<"El sou net del treballador es: "<<souf<<" euros."<<endl;
    }
    else{cout<<"Les dades no son valides."<<endl;}
}
