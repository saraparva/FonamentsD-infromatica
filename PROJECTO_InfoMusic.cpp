#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

//DEFINICIONES TUPLES

struct lista{
    vector<char> cantante;
    vector<char> cancion;
    int año;
    string genero;
};

//DEFINICIÓN DE FUNCIONES

void llegir_fitxer(vector<lista> &playlist);
void escribir_info(vector<lista> &playlist, int i);
void busqueda(vector<lista> &playlist, vector<lista> &mi_lista, int opc);
void cercaperautor(vector<lista> &playlist, vector<char> &autor);
void cercapercanco(vector<lista> &playlist, vector<char> &canco);
void afegir(vector<lista> &playlist, int i, vector<lista> &mi_lista);
void modificar(vector<lista> &mi_lista);
void eliminar(vector<lista> &mi_lista);

//MAIN

int main(){
    int opc,  opc2;
    string menu;
    bool continuar=true;
    vector<lista> playlist, mi_lista, busquedes;
    llegir_fitxer(playlist);
    while(continuar){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"1. Cercar"<<endl;
        cout<<"2. La meva llista"<<endl;
        cout<<"3. Sortir"<<endl;
        cin>>opc;
        if(opc>=1 && opc<=3){
            switch(opc){
                case 1:
                    busqueda(playlist,mi_lista,opc);
                    cout<<"Vols tornar al menú principal? (Si/No) "<<endl;
                    cin>>menu;
                    if(menu=="No"){continuar=false;}
                    break;
                case 2:
                    cout<<endl<<"LA TEVA LLISTA"<<endl;
                    cout<<"1. Busqueda"<<endl;
                    cout<<"2. Modificar"<<endl;
                    cout<<"3. Eliminar"<<endl;
                    cin>>opc2;
                    while(opc2>=1 && opc2<=3){
                        switch(opc2){
                            case 1:
                                busqueda(playlist, mi_lista, opc);
                                break;
                            case 2:
                                //cout...
                                modificar(mi_lista);
                                break;
                            case 3:
                                //cout...
                                eliminar(mi_lista);
                                break;
                            default:;
                        }
                    }
                    cout<<"Vols tornar al menú principal? (Si/No)"<<endl;
                    cin>>menu;
                    if(menu=="No"){continuar=false;}
                    break;
                case 3:
                    continuar=false;
                    break;
                default:;
            }
        }
        else{
            cout<<"Opcio no valida."<<endl;
            continuar=true;
        }
    }
}

//FUNCIONES

void llegir_fitxer(vector<lista> &playlist){
    ifstream dades("BaseDeDatos.txt");
    lista l;
    char c;
    while(!dades.eof()){
        dades.get(c);
        while(c!='-'){
            l.cantante.push_back(c);
            dades.get(c);
        }
        dades.get(c);
        while(c!='-'){
            l.cancion.push_back(c);
            dades.get(c);
        }
        dades>>l.año;
        //por el ‘-’ que separa año y género en los datos
        dades>>c;
        dades>>l.genero;
        playlist.push_back(l);
        //para que no se acumulen los caracteres
        l.cantante.clear();
        l.cancion.clear();
    }
}

void escribir_info(vector<lista> &playlist, int i){
    int a;
    long int dimcant=playlist[i].cantante.size(), dimcanc=playlist[i].cancion.size();
    cout<<"Autor:";
    for(a=0;a<dimcant;a++){
        cout<<playlist[i].cantante[a];
    }
    cout<<endl<<"Cancion:";
    for(a=0;a<dimcanc;a++){
        cout<<playlist[i].cancion[a];
    }
    cout<<endl<<"Año: "<<playlist[i].año<<endl;
    cout<<endl<<"Genero: "<<playlist[i].genero<<endl<<endl;
}

void busqueda(vector<lista> &playlist, vector<lista> &mi_lista, int opc){
    char c;
    string opc2;
    int opc3;
    vector<char> autor, canco;
    cout<<endl<<"MENU DE BUSQUEDA"<<endl;
    cout<<"1. Per autoria"<<endl;
    cout<<"2. Per canço"<<endl;
    cin>>opc3;
    while(opc3>=1 &&opc3<=2){
        switch(opc3){
            case 1:
                cout<<"Nom de l’autor: (Acabat en punt)"<<endl;
                cin.get(c);
                while(c!='.'){
                    autor.push_back(c);
                    cin.get(c);
                }
                if(opc==1){
                    cercaperautor(playlist,autor);
                    cout<<"Vols afegir a la teva llista? (Si/No)"<<endl;
                    cin>>opc2;
                    if(opc2=="Si"){
                        afegir(playlist,i,mi_lista);
                    }
                }
                else{
                    cercaperautor(mi_lista,autor);
                    cout<<"Vols afegir a la teva llista? (Si/No)"<<endl;
                    cin>>opc2;
                    if(opc2=="Si"){
                        afegir(playlist,i,mi_lista);
                    }
                }
                break;
            case 2:
                cout<<"Nom de la canço: (Acabat en punt)"<<endl;
                cin.get(c);
                while(c!='.'){
                    canco.push_back(c);
                    cin.get(c);
                }
                if(opc==1){
                    cercapercanco(playlist,canco);
                    cout<<"Vols afegir a la teva llista? (Si/No)"<<endl;
                    cin>>opc2;
                    if(opc2=="Si"){
                        afegir(playlist,i,mi_lista);
                    }
                }
                else{
                    cercapercanco(mi_lista,canco);
                    cout<<"Vols afegir a la teva llista? (Si/No)"<<endl;
                    cin>>opc2;
                    if(opc2=="Si"){
                        afegir(playlist,i,mi_lista);
                    }
                }
                break;
            default:;
        }
    }
}

void cercaperautor(vector<lista> &playlist, vector<char> &autor){
void cercapercanco(vector<lista> &playlist, vector<char> &canco){
void afellir(vector<lista> &playlist, int i, vector<lista> &mi_lista){
void modificar(vector<lista> &mi_lista){
void eliminar(vector<lista> &mi_lista){

