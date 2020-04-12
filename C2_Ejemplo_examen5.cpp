#include <iostream>
using namespace std;

void info_codi(long int codi, int &cpais){
    long int CODI;
    int dcontrol, ieditor, tpubli;
    CODI=codi;
    dcontrol=codi%10;
    ieditor=(codi/10)%100;
    tpubli=(codi/1000)%10;
    while(codi>=100){
        codi/=10;
        cpais=codi;
    }
    cout<<CODI<<" on el editor es "<<ieditor<<", "<<tpubli<<"  es el tipus de publicacio i "<<cpais<<" el codi de pais."<<endl;
}
void codi_pais(int cpais){
    if(cpais==84){
        cout<<"El codi de pais es el d'Espanya."<<endl;
    }
    else{
        cout<<"El codi de pais no es el d'Espanya."<<endl;
    }
}

int main(){
    long int codi;
    int cpais;
    cin>>codi;
    info_codi(codi,cpais);
    codi_pais(cpais);
}
