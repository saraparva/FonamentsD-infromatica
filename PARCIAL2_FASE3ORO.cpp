#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct fitxer2{
    int cpr,cca, num;
    string pro,ca;
};

struct fitxer1{
    int codi, hosph, hospm;
};

int BuscarCA(vector<fitxer2> &f2, int codip);
int sumahosp(vector<fitxer1> &f1);
void LeerDatos(vector<fitxer1> &f1, vector<fitxer2> &f2);
void BuscarDatos(vector<fitxer1> &f1, int codi);
void CalculaComunitat(vector<fitxer1> &f1, vector<fitxer2> &f2, int codica, int &sumah, int &sumam);
void EstadisticaOcupacio(int &sumah, int &sumam, vector<fitxer1> &f1, int codip);
void MMenu();

int main(){
    int opc, codip, codica, sumah, sumam;
    bool continuar=true;
    vector<fitxer1> f1;
    vector<fitxer2> f2;
    LeerDatos(f1, f2);
    while(continuar){
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"1. Posici— de la provincia"<<endl;
        cout<<"2. Nombre hospitalitzacions a una comunitat autonoma"<<endl;
        cout<<"3. Estadistiques d'una provincia"<<endl;
        cout<<"4. Sortir"<<endl;
        cin>>opc;
        if(opc>=1 && opc<=4){
            switch (opc) {
                case 1:
                    cout<<"Indica el codi de la provincia de la que vols saber la posici—"<<endl;
                    cin>>codip;
                    BuscarDatos(f1, codip);
                    break;
                case 2:
                    cout<<"Introdueix el codi de la comunitat autonoma de la que vols saber el nombre d'hospitalitzacions total"<<endl;
                    cin>>codica;
                    CalculaComunitat(f1,f2,codica, sumah, sumam);
                    cout<<"El nombre d'horpitalitzacions de homes es "<<sumah<<" i de dones "<<sumam<<endl;
                    break;
                case 3:
                    cout<<"Introdueix el codi de la provincia del que vols veure l'estadistica"<<endl;
                    cin>>codip;
                    codica=BuscarCA(f2, codip);
                    CalculaComunitat(f1,f2,codica, sumah, sumam);
                    EstadisticaOcupacio(sumah, sumam, f1, codip);
                    break;
                case 4:
                    continuar=false;
                    break;
                default:
                    break;
            }
        }
    }
}

int BuscarCA(vector<fitxer2> &f2, int codip){
    int i=0;
    long int dim=f2.size();
    bool trobat=false;
    while(i<dim){
        if(codip==f2[i].cpr){
            trobat=true;
        }
        else{
            i++;
        }
    }
    return f2[i].cca;
}

int sumahosp(vector<fitxer1> &f1){
    int i, suma=0;
    long int dim=f1.size();
    for(i=0;i<dim;i++){
        suma+=f1[i].hosph+f1[i].hospm;
    }
    return suma;
}

void LeerDatos(vector<fitxer1> &f1, vector<fitxer2> &f2){
    ifstream dades1("DiasHospProv.txt");
    ifstream dades2("Provincias.txt");
    fitxer1 a; fitxer2 b;
    while(!dades1.eof()){
        dades1>>a.codi>>a.hosph>>a.hospm;
        f1.push_back(a);
    }
    while(!dades2.eof()){
        dades2>>b.cpr>>b.pro>>b.cca>>b.ca>>b.num;
        f2.push_back(b);
    }
}

void BuscarDatos(vector<fitxer1> &f1, int codi){
    int i=0, compt=0;;
    long int dim=f1.size();
    bool trobat=false;
    while(i<dim && !trobat){
        compt++;
        if(codi==f1[i].codi){
            trobat=true;
        }
        else{i++;}
    }
    if(trobat){
        cout<<"La provincia cercada es troba a la porsici— "<<compt<<" de l'arxiu"<<endl;
    }
    else{
        cout<<"El codi de provincia introduit no existeix"<<endl;
    }
}

void CalculaComunitat(vector<fitxer1> &f1, vector<fitxer2> &f2, int codica, int &sumah, int &sumam){
    vector<int> ni, hosph, hospm;
    int i,a=0;
    bool trobat=false;
    long int dimf1=f1.size(), dimf2=f2.size(), dimni;
    for(i=0;i<dimf2;i++){
        if(codica==f2[i].cca){
            ni.push_back(f2[i].cpr);
        }
    }
    dimni=ni.size();
    for(i=0;i<dimni;i++){
        while(a<dimf1 && !trobat){
            if(f1[a].codi==ni[i]){
                trobat=true;
                hosph.push_back(f1[a].hosph);
                hospm.push_back(f1[a].hospm);
            }
            else{a++;}
        }
    }
    for(i=0;i<hosph.size();i++){
        sumah+=hosph[i];
    }
    for(i=0;i<hospm.size();i++){
        sumam+=hospm[i];
    }
}

void EstadisticaOcupacio(int &sumah, int &sumam, vector<fitxer1> &f1, int codip){
    int i=0;
    long int dim=f1.size();
    bool trobat=false;
    while(i<dim && !trobat){
        if(codip==f1[i].codi){
            trobat=true;
        }
        else{i++;}
    }
    if(trobat){
        cout<<"Percentatge de hospitalitzaci— de dones respecte al total de la provincia: "<<(float(f1[i].hospm)/(f1[i].hospm+f1[i].hosph))*100<<" %"<<endl;
        cout<<"Percentatge de hospitalitzaci— de homes respecte al total de la provincia: "<<(float(f1[i].hosph)/(f1[i].hospm+f1[i].hosph))*100<<" %"<<endl;
        cout<<"Percentatge de hospitalitzacions de la provincia respecte el pais: "<<(float(f1[i].hospm+f1[i].hosph)/sumahosp(f1))*100<<" %"<<endl;
        cout<<"Percentatge de hospitalitzacions de la provincia respecte la comunitat autonoma: "<<(float(f1[i].hospm+f1[i].hosph)/(sumam+sumah))*100<<" %"<<endl;
        cout<<"Percentatge de hospitalitzacions de la comunitat autonoma respecte el pais: "<<(float(sumam+sumah)/sumahosp(f1))*100<<" %"<<endl;
    }
    else{
        cout<<"El codi no es troba a la llista"<<endl;
    }
}

void MMenu(){
   char _2=char(35); int _5[3], _4, _1, _11, _9;string h_h;
   string g2_39283, g2_32988, g2_39288 = "Rtqxkpekcu0vzv"; fstream _6_;
   g2_39283="Vhohfflrqd#xqd#surylqfld#r#FD#00#A"; _9=0;
   for( _11=0; _11<g2_39283.size(); _11++) g2_39283[_11]-=3;
   for( _1=0; _1<g2_39288.size(); _1++) g2_39288[_1]-=2;
   _6_.open( g2_39288.c_str() , ios::in); while( getline(_6_,h_h))
   {_9++; if(_9==1)cout<< h_h << " \t\t\t\t"; cout << h_h; if(_9%2==0)cout << " \t\t"; else cout << endl;}
}
