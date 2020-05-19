#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool trobat(vector<string> matriculas, vector<int> horas);

int main(){
    ifstream fin("cobros.txt");
    vector<string> matriculas;
    vector<int> horas;
    string matricula;
    int hora;
    while(fin>>matricula>>hora){
        matriculas.push_back(matricula);
        horas.push_back(hora);
        trobat(matriculas,horas);
        if (trobat){
            cout<<"¡COBRO DOBLE! Producido a la matricula "<<matricula<<"a las "<<hora<<" horas."<<endl;
        }
        else{
            cout<<"Todo correcto"<<endl;
        }
    }
}

bool trobat(vector<string> matriculas, vector<int> horas){
    int dim, i=0;
    bool same=false;
    dim=horas.size();
    while(!same){
        if(matriculas[dim-1]==matriculas[i] && horas[dim-1]==horas[i]){
            same=true;
        }
        i++;
    }
    if(same){return true;}
    else{return false;}
}
