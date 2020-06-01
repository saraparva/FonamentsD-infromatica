#include <iostream>
using namespace std;

struct data{
    int dia;
    int mes;
    int any;
};

struct espectacle{
    string nom;
    string tipus;
    data datai;
    data dataf;
    float preu;
};

void guardar_informacio(espectacle &esp);

bool validar_data(data dataobs, data datai, data dataf);

void escriure_esp(espectacle &esp);

int main(){
    espectacle esp;
    data dataobs;
    bool trobat=false;
    cout<<"Quina es la data de la que vols informacio?"<<endl;
    cin>>dataobs.dia>>dataobs.mes>>dataobs.any;
    guardar_informacio(esp);
    while(esp.nom!="fi" && !trobat){
        if(validar_data(dataobs, esp.datai, esp.dataf)){
            escriure_esp(esp);
        }
        guardar_informacio(esp);
    }
}

void guardar_informacio(espectacle &esp){
    cout<<"Escriu l'informació sobre l'espectacle: nom, tipus, data d'inici, data de finalitzacio i preu."<<endl;
    cin>>esp.nom;
    while(esp.nom!="fi"){
        cin>>esp.tipus>>esp.datai.dia>>esp.datai.mes>>esp.datai.any>>esp.dataf.dia>>esp.dataf.mes>>esp.dataf.any>>esp.preu;
    }
}

bool validar_data(data dataobs, data datai, data dataf){
    bool res=false;
    if(dataobs.any>=datai.any && dataobs.any<=dataf.any){
        if(dataobs.mes>=datai.mes && dataobs.mes<=dataf.mes){
            if(dataobs.dia>=datai.dia && dataobs.dia<=dataf.dia){
                res=true;
            }
        }
    }
    return res;
}

void escriure_esp(espectacle &esp){
    cout<<esp.nom<<": concert de "<<esp.tipus<<" des de el "<<esp.datai.dia<<'/'<<esp.dati.mes<<'/'<<esp.datai.any;
    cout<<" fins el"<<esp.dataf.dia<<'/'<<esp.dataf.mes<<'/'<<esp.dataf.any<<" i el seu preu es: "<<esp.preu<<endl;
}
