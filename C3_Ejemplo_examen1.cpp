//Grau GREVA Control 4, 2019 Tardor Dimarts, 17 de Desembre

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct viatge{
    string nom, desti;
    int dia, mes, dies;
    float preu;
};

void llegir_fitxer(vector<viatge> &viajes);
void escriure_info(vector<viatge> &viajes, int opc, int i, int dia, int mes);
void cercar_perdata(vector<viatge> &viajes, int diaviaje, int mesviaje, int dies, int dia, int mes);
void cercar_perviatge(vector<viatge> &viajes, string nom_viatge, int dia, int mes);

int main(){
    int dia, mes, diaviaje, mesviaje, opc, num_dies;
    string nom_viatge;
    vector<viatge> viajes;
    llegir_fitxer(viajes);
    cout<<"Quin dia es?"<<endl;
    cin>>dia>>mes;
    cout<<"MENU D'OPCIONS DE BUSQUEDA"<<endl;
    cout<<"1. Per data d'inici"<<endl;
    cout<<"2. Per nom de viatge"<<endl;
    cin>>opc;
    while(opc>=1 && opc<=2){
        switch(opc){
            case 1:
                cout<<"Introdueix la data a la que vols viatjar i el numero de dies."<<endl;
                cin>>diaviaje>>mesviaje>>num_dies;
                cercar_perdata(viajes, diaviaje, mesviaje, num_dies, dia, mes);
                break;
            case 2:
                cout<<"Introdueix el nom del viatge.";
                cin>>nom_viatge;
                cercar_perviatge(viajes, nom_viatge, dia, mes);
                break;
            default:;
        }
    }
}

void llegir_fitxer(vector<viatge> &viajes){
    viatge v;
    ifstream fi("Ultiminutviatges.txt");
    while(!fi.eof()){
        fi>>v.nom>>v.desti>>v.dia>>v.mes>>v.dies>>v.preu;
        viajes.push_back(v);
    }
}

void escriure_info(vector<viatge> &viajes, int opc, int i, int dia, int mes){
    int dia2, mes2, dies, interes=1;
    int datahoy,dataviaje, tiempo;
    datahoy=mes*30+dia;
    dataviaje=viajes[i].mes*30+viajes[i].dia;
    tiempo=dataviaje-datahoy;
    if(tiempo<=14 && tiempo>=7){
        interes=0.8;
    }
    else{if(tiempo<7){
        interes=0.6;
        }
    }
    
    if(opc==1){
        cout<<viajes[i].nom<<' '<<viajes[i].desti<<' '<<viajes[i].dia<<'/'<<viajes[i].mes<<' '<<viajes[i].dies<<" dies "<<(viajes[i].preu)*interes<<" euros."<<endl;
    }
    else{
        dies=viajes[i].dia+viajes[i].dies;
        if(dies>30){
            dia2=dies-30;
            mes2=viajes[i].mes+1;
        }
        else{
            dia2=dies;
            mes2=viajes[i].mes;
        }
        cout<<viajes[i].nom<<": "<<viajes[i].desti<<" del "<<viajes[i].dia<<'/'<<viajes[i].mes<<" al "<<dia2<<'/'<<mes2<<' '<<(viajes[i].preu)*interes<<" euros."<<endl;
    }
}

void cercar_perdata(vector<viatge> &viajes, int diaviaje, int mesviaje, int dies, int dia, int mes){
    int i, opc=1, trobat=0;
    long int dim=viajes.size();
    for(i=0;i<dim;i++){
        if(viajes[i].dia==dia && viajes[i].mes==mes && viajes[i].dies==dies){
            trobat++;
            escriure_info(viajes, opc, i, dia, mes);
        }
    }
    if(trobat==0){
        cout<<"No s'ha trobat cap oferta."<<endl;
    }
}

void cercar_perviatge(vector<viatge> &viajes, string nom_viatge, int dia, int mes){
    int i, opc=2, trobat=0;
    long int dim=viajes.size();
    for(i=0;i<dim;i++){
        if(viajes[i].nom==nom_viatge){
            trobat++;
            escriure_info(viajes, opc, i, dia, mes);
        }
    }
    if(trobat==0){
        cout<<"No s'ha trobat cap oferta."<<endl;
    }
}
