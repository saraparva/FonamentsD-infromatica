#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct persona{
    int dni;
    char genere;
    int edat
    float reg1, reg2, reg3, promedio;
};

float promedio(float reg1, float reg2, float reg3);
bool sospitos(float reg1, float reg2, float reg3);
void llegirfitxer(vector<persona> &pers);
void separarpergenere(vector<persona> &pers,  vector<persona> &dni_dones, vector<persona> &dni_homes);
void guardararxius(vector<persona> &pers, vector<persona> &dni_dones, vector<persona> &dni_homes);
void estadistica(int dim, int dimdon, int dimhom);

int main(){
    int opc;
    vector<persona> pers;
    vector<persona> dni_dones;
    vector<persona> dni_homes;
    llegirfitxer(pers);
    separarpergenere(pers,dni_dones,dni_homes);
    cout<<"MENU D'OPCIONS"<<endl;
    cout<<"1. Separar per genere i guardar als arxius."<<endl;
    cout<<"2. Mostrar estadistica."<<endl;
    cin>>opc;
    if(opc>=1 && opc<=2){
        switch(opc){
            case 1:
                guardararxius(pers,dni_dones,dni_homes);
                break;
            case 2:
                estadistica(pers.size(),dni_dones.size(),dni_homes.size());
                break;
            default:;
        }
    }
    else{
        cout<<"Opcio incorrecte"<<endl;
    }
}

float promedio(float reg1, float reg2, float reg3){
    float mig, suma;
    suma=reg1+reg2+reg3;
    mig=suma/3;
    return mig;
}

bool sospitos(float reg1, float reg2, float reg3){
    if( (reg1>37.9 && reg2>37.9) || (reg2>37.9 && reg3>37.9)){ ///si dos nombres consecutius son mayors de 37.9 es sospitos
        return true;
    }
    else{
        return false;
    }
}

void llegirfitxer(vector<persona> &pers){
    ifstream fi("cuarentena.txt");
    persona p;
    while(!fi.eof()){
        fi>>p.dni>>p.genere>>p.edat>>p.reg1>>p.reg2>>p.reg3;
        p.promedio=promedio(p.reg1,p.reg2,p.reg3);
        pers.push_back(p);
    }
}

void separarpergenere(vector<persona> &pers,  vector<persona> &dni_dones, vector<persona> &dni_homes){
    int i;
    long int dim=pers.size();
    for(i=0;i<dim;i++){
        if(sospitos(pers[i].reg1, pers[i].reg2, pers[1].reg3)){
            if(pers[i].genere=='F'){ /// per veure si coincideixen;
                dni_dones.push_back(pers[i]);
            }
            else{ ///suposant que no hi pot haver cap altra lletra diferent de F i M;
                dni_homes.push_back(pers[i]);
            }
        }
    }
}

void guardararxius(vector<persona> &pers, vector<persona> &dni_dones, vector<persona> &dni_homes){
    ofstream dones("SospechosAs_2.txt");
    ofstream homes("SospechosOs_2.txt");
    int i;
    long int dimdon=dni_dones.size(), dimhom=dni_homes.size();
    dones<<"Hi ha hagut un total de: "<<dimdon<<" casos sospitosos a dones."<<endl;
    homes<<"Hi ha hagut un total de: "<<dimhom<<" casos sospitosos a homes."<<endl;
    for(i=0;i<dimdon;i++){
        dones<<dni_dones[i].dni<<' '<<dni_dones[i].genere<<' '<<dni_dones[i].edat<<' '<<dni_dones[i].promedio<<endl;
    }
    for(i=0;i<dimhom;i++){
        homes<<dni_homes[i].dni<<' '<<dni_homes[i].genere<<' '<<dni_homes[i].edat<<' '<<dni_homes[i].promedio<<endl;
    }
}

void estadistica(int dim, int dimdon, int dimhom){
    cout<<"De un total de "<<dim<<" persones analitzades, hi ha un total de "<<dimdon+dimhom<<" casos sospitosos."<<endl;
    cout<<"D'aquests casos hi han: "<<dimdon<<" dones sospitosos i "<<dimhom<<" homes sospitosos."<<endl;
    cout<<"ESTADISTICA"<<endl;
    cout<<"Percentatge de dones sospitosas: "<<(float(dimdon)/dim)*100<<" %"<<endl;
    cout<<"Percentatge d'homes sospitosos: "<<(float(dimhom)/dim)*100<<" %"<<endl;
}
