#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct viatge{
    string nom, desti;
    int dia, mes, duracio;
    float preu;
};

float calculimpost(int dia, int mes, int diahoy, int meshoy);
void llegir_fitxer(vector<viatge> &via);
void cercardata(vector<viatge> &via, int dia, int mes, int duracio, int opc, int diahoy, int meshoy);
void cercarnom(vector<viatge> &via, string nom, int opc, int diahoy, int meshoy);
void escriureviatge(vector<viatge> &via, int i, int opc, int diahoy, int meshoy);

int main(){
    int diahoy, meshoy, opc, diav, mesv, dura;
    string nom_viatge;
    vector<viatge> via;
    llegir_fitxer(via);
    cout<<"Escriu el dia i el mes d'avui."<<endl;
    cin>>diahoy>>meshoy;
    cout<<"MENU DE BUSQUEDA"<<endl;
    cout<<"1. Busqueda per data d'inici"<<endl;
    cout<<"2. Busqueda per nom de viatge"<<endl;
    cout<<"3. Sortir"<<endl;
    cin>>opc;
    while(opc>=1 && opc<=2){
        switch(opc){
            case 1:
                cout<<"Dia: ";
                cin>>diav;
                cout<<" Mes: ";
                cin>>mesv;
                cout<<" Duració: ";
                cin>>dura;
                cercardata(via, diav, mesv, dura, opc, diahoy, meshoy);
                break;
            case 2:
                cout<<"Nom del viatge: ";
                cin>>nom_viatge;
                cercarnom(via, nom_viatge, opc, diahoy, meshoy);
                break;
            default:;
        }
    }
}

float calculimpost(int dia, int mes, int diahoy, int meshoy){
    int inici, avui;
    float impost;
    inici=mes*30+dia;
    avui=meshoy*30+diahoy;
    if((inici-avui)<14){
        if((inici-avui)<=7){ ///menys 7
            impost=0.6;
        }
        else{
            impost=0.8;
        }
    }
    else{impost=1;}
    return impost;
}

void llegir_fitxer(vector<viatge> &via){
    ifstream fi("Ultiminutviatges.txt");
    viatge v;
    while(!fi.eof()){
        fi>>v.nom>>v.desti>>v.dia>>v.mes>>v.duracio>>v.preu;
        via.push_back(v);
    }
}

void cercardata(vector<viatge> &via, int dia, int mes, int duracio, int opc, int diahoy, int meshoy){
    int i, compt=0;
    long int dim=via.size();
    for(i=0;i<dim;i++){
        if(via[i].dia==dia && via[i].mes==mes && via[i].duracio==duracio){
            compt++;
            escriureviatge(via,i,opc, diahoy, meshoy);
        }
    }
    if(compt==0){
        cout<<"No hi ha cap viatge disponible."<<endl;
    }
}

void cercarnom(vector<viatge> &via, string nom, int opc, int diahoy, int meshoy){
    int i, compt=0;
    long int dim=via.size();
    for(i=0;i<dim;i++){
        if(via[i].nom==nom){
            compt++;
            escriureviatge(via,i,opc,diahoy,meshoy);
        }
    }
    if(compt==0){
        cout<<"No hi ha cap viatge disponible."<<endl;
    }
}

void escriureviatge(vector<viatge> &via, int i, int opc, int diahoy, int meshoy){
    int diaf, mesf, aux;
    float impost=calculimpost(via[i].dia, via[i].mes, diahoy, meshoy);
    if(opc==1){
        cout<<via[i].nom<<' '<<via[i].desti<<' '<<via[i].dia<<'/'<<via[i].mes<<' ';
        cout<<via[i].duracio<<" dies "<<via[i].preu*impost<<" euros"<<endl;
    }
    else{
        aux=via[i].dia+via[i].duracio;
        if(aux>30){
            diaf=aux-30;
            mesf=via[i].mes+1;
        }
        else{
            diaf=aux;
            mesf=via[i].mes;
        }
        cout<<via[i].nom<<": "<<via[i].desti<<" del "<<via[i].dia<<'/'<<via[i].mes;
        cout<<" al "<<diaf<<'/'<<mesf<<' '<<via[i].preu*impost<<" euros"<<endl;
    }
}
