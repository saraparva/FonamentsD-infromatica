#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct dades{
    string codi, nom, cognoms, lleng;
    int edat;
};

int aficionats(vector<dades> &fit,string lleng);
void llegir_fitxer(vector<dades> &fit);


int main(){
    vector<dades> fit;
    string llenguatge;
    int aficionados;
    cout<<"Indica el llenguatge dels que vols saber el nombre d'aficionats"<<endl;
    cin>>llenguatge;
    aficionados=aficionats(fit,llenguatge);
    if(aficionados==0){
        cout<<"HEM DE BUSCAR SOCIS AFICIONATS A AQUEST LLENGUATGE"<<endl;
    }
    else{
        cout<<"El nombre d'aficionats al "<<llenguatge<<" es: "<<aficionados<<endl;
    }
}

int aficionats(vector<dades> &fit,string lleng){
    int i, compt=0;
    long int dim=fit.size();
    for(i=0;i<dim;i++){
        if(fit[i].lleng==lleng){
            compt++;
        }
        i++;
    }
    return compt;
}

void llegir_fitxer(vector<dades> &fit){
    dades f;
    ifstream fin("programadors.txt");
    while(!fin.eof()){
        fin>>f.codi>>f.nom>>f.cognoms>>f.edat>>f.lleng;
        fit.push_back(f);
    }
}
