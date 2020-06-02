#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct cotxe{
    string matricula, marca;
    float co2, impost;
};

struct emissions{
    string marca;
    float co2;
};

float calcul_impost(float emisiones);
float calcul_impost(float emisiones);
void llegir_fitxers(vector<cotxe> &cot, vector<emissions> &emi);
void unio_dades(vector<cotxe> &cot, vector<emissions> &emi);
void escriu_resultats(vector<cotxe> &cot);
void cerca_escriptura(vector<cotxe> &cot, string matricula);

int main(){
    string matricula;
    vector<cotxe> cot;
    vector<emissions> emi;
    llegir_fitxers(cot, emi);
    unio_dades(cot,emi);
    escriu_resultats(cot);
    cout<<"Escriu les matricules a consultar"<<endl;
    cin>>matricula;
    while(matricula!="000"){
        cerca_escriptura(cot,matricula);
    }
}

float cercar_consum(string marca, vector<emissions> &emi){
    int i=0;
    long int dim=emi.size();
    float emisiones;
    bool trobat=false;
    while(i<dim && !trobat){
        if(marca==emi[i].marca){
            emisiones=emi[i].co2;
            trobat=true;
        }
        else{i++;}
    }
    return emisiones;
}

float calcul_impost(float emisiones){
    float impost;
    if(emisiones>=95){
        if(emisiones<=140){
            impost=emisiones*0.7;
        }
        else{if(emisiones<=200){
                impost=emisiones*1.1;
            }
            else{
                impost=emisiones*1.4;
            }
        }
    }
    else{
        impost=0.0;
    }
    return impost;
}

void llegir_fitxers(vector<cotxe> &cot, vector<emissions> &emi){
    ifstream dademi("emissionsCO2.txt");
    ifstream dadcot("cars.txt");
    cotxe c;
    emissions e;
    while(!dademi.eof()){
        dademi>>e.marca>>e.co2;
        emi.push_back(e);
    }
    while(!dadcot.eof()){
        dadcot>>c.matricula>>c.marca;
        cot.push_back(c);
    }
}

void unio_dades(vector<cotxe> &cot, vector<emissions> &emi){
    int i;
    long int dimcot=cot.size();
    for(i=0;i<dimcot;i++){
        cot[i].co2=cercar_consum(cot[i].marca, emi);
        cot[i].impost=calcul_impost(cot[i].co2);
    }
}

void escriu_resultats(vector<cotxe> &cot){
    int i;
    long int dim=cot.size();
    ofstream resultats("carsTot.txt");
    resultats<<"Matricula Marca grCO2/km Impost"<<endl;
    for(i=0;i<dim;i++){
        resultats<<cot[i].matricula<<' '<<cot[i].marca<<' ';
        resultats<<cot[i].co2<<' '<<cot[i].impost<<endl;
    }
}

void cerca_escriptura(vector<cotxe> &cot, string matricula){
    int i;
    long int dim=cot.size();
    bool trobat=false;
    while(i<dim && !trobat){
        if(cot[i].matricula==matricula){
            trobat=true;
        }
        else{i++;}
    }
    cout<<cot[i].matricula<<' '<<cot[i].marca<<' '<<cot[i].co2<<' '<<cot[i].impost<<endl;
}
