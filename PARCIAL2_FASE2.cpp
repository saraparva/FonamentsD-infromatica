#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct hospitales{
    int codi, enfermetat, dies;
    char genere;
};

struct fitxer{
    int codi, hosph, hospm;
};

bool trobat(int codi, vector<int> &codip);
void llegir(vector<hospitales> &h);
void separarcodi(vector<hospitales> &h, vector<int> &codip);
void dadessortida(vector<hospitales> &h, vector<int> &codip, vector<fitxer> &f);
void sortir(vector<fitxer> &f);

int main(){
    long int dim;
    vector<hospitales> h;
    vector<int> codip;
    vector<fitxer> f;
    llegir(h);
    separarcodi(h,codip);
    dadessortida(h,codip,f);
    dim=f.size();
    sortir(f);
    cout<<"S'han afegit un nombre de "<<dim<<" files al fitxer"<<endl;
}

bool trobat(int codi, vector<int> &codip){
    int i=0;
    bool trobat=false;
    long int dim=codip.size();
    while(i<dim && !trobat){
        if(codip[i]==codi){
            trobat=true;
        }
        else{i++;}
    }
    if(trobat){ //El codi ja es troba al vector
        return false;
    }
    else{
        return true;
    }
}

void llegir(vector<hospitales> &h){
    ifstream dades("DiasEstanciaHospitales.txt");
    string s;
    hospitales hosp;
    ///Introduim els noms inicials de les 4 columnes
    dades>>s>>s>>s>>s;
    while(!dades.eof()){
        dades>>hosp.codi>>hosp.enfermetat>>hosp.dies>>hosp.genere;
        h.push_back(hosp);
    }
}

void separarcodi(vector<hospitales> &h, vector<int> &codip){
    int i;
    long int dim=h.size();
    codip.push_back(h[0].codi);
    for(i=0;i<dim;i++){
        if(!trobat(h[i].codi,codip)){
            codip.push_back(h[i].codi);
        }
    }
}

void dadessortida(vector<hospitales> &h, vector<int> &codip, vector<fitxer> &f){
    int i, a, sumah, sumam, compt;
    long int dimh=h.size(), dimc=codip.size();
    fitxer d;
    for(i=0;i<dimc;i++){
        sumah=0; sumam=0;
        d.codi=codip[i];
        for(a=0;a<dimh;a++){
            compt=0;
            while(codip[i]==h[a].codi){
                compt++;
                if(h[a].genere=='H'){
                    sumah+=h[a].dies;
                }
                else{ //Com que si no es H serˆ M
                    sumam+=h[a].dies;
                }
            }
            if(compt!=0){
                d.hosph=sumah;
                d.hospm=sumam;
                f.push_back(d);
            }
        }
    }
}

void sortir(vector<fitxer> &f){
    ofstream s("DiesEstadaProvIGenere.txt");
    int i;
    long int dim=f.size();
    cout<<"CodiProv  Dieshosphom  Dieshospdon"<<endl;
    for(i=0;i<dim;i++){
        s<<f[i].codi<<' '<<f[i].hosph<<' '<<f[i].hospm<<endl;
    }
}
