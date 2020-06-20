#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <locale.h>
using namespace std;

struct data{
    int dia;
    int mes;
    int any;
};

struct lista{
    vector<char> cantante;
    vector<char> cancion;
    int any;
    string genero;
};

bool coincidir(vector<char> &cantante, vector<char> &autor);
void logo(char x);
void llegir_dades(vector<lista> &playlist);
void llegir_llista(vector<lista> &mi_lista, vector<data> &dates);
void escribir_info(vector<lista> &playlist, int i);
void sortida_fitxer(vector<lista> &mi_lista, vector<data> &dates);
void afegir(vector<lista> &mi_lista, vector<lista> &playlist);
void modificar(vector<lista> &mi_lista, vector<data> &dates, int i, data d);
void eliminar(vector<lista> &mi_lista, vector<data> &dates, int i);
void recomendacion(vector<lista> &playlist, vector<lista> &mi_lista, lista busquedes);
void busqueda(vector <lista> &playlist,vector<lista> &busquedes, vector<int> &ni);
void opciones(vector <lista> &playlist,vector<lista> &mi_lista, vector<lista> &busquedes,  vector<data> &dates, vector<int> &ni, int opc, data d);

int main(){
    //Per poder incloure accents i caracters especials hem afegit:
    setlocale(LC_CTYPE, "Spanish");
    int opc, opc2, opc3;
    string menu;
    char x='x';
    bool continuar=true, continuar2;
    data d;
    vector<int> ni;
    vector<data> dates;
    vector<lista> playlist, mi_lista, busquedes;
    logo(x);
    cout<<"Carregant dades..."<<endl;
    llegir_dades(playlist);
    llegir_llista(mi_lista, dates);
    system("cls");
    logo(x);
    cout<<endl<<"Benvingut a Info-Music"<<endl;
    cout<<"Indica la data d'avui (dia mes any): ";
    cin>>d.dia>>d.mes>>d.any;
    while(continuar){
        system("cls");
        logo(x);
        cout<<endl<<"MENU PRINCIPAL"<<endl;
        cout<<"1. Cercar"<<endl;
        cout<<"2. La meva llista"<<endl;
        cout<<"3. Sortir"<<endl;
        cin>>opc;
        if(opc>=1 && opc<=3){
            switch(opc){
                case 1:
                    continuar2=true;
                    while(continuar2){
                        cout<<endl<<"LLOCS DE CERCA"<<endl;
                        cout<<"1. Base de dades"<<endl;
                        cout<<"2. La meva llista"<<endl;
                        cout<<"3. Sortir"<<endl;
                        cin>>opc2;
                        if(opc2>=1 && opc2<=3){
                            switch(opc2){
                                case 1:
                                    busqueda(playlist,busquedes,ni);
                                    if(busquedes.size()>0){
                                        opciones(playlist, mi_lista, busquedes, dates, ni, opc2, d);
                                    }
                                    break;
                                case 2:
                                    busqueda(mi_lista,busquedes,ni);
                                    if(busquedes.size()>0){
                                        opciones(playlist, mi_lista, busquedes, dates, ni, opc2, d);
                                    }
                                    break;
                                case 3:
                                    cout<<"Tornant al menú principal..."<<endl;
                                    continuar2=false;
                                    break;
                                default:;
                            }
                        }
                        else{cout<<"No s’ha escogit cap opció valida"<<endl;}
                    }
                    break;
                case 2:
                    continuar2=true;
                    while(continuar2){
                        cout<<endl<<"LA TEVA LLISTA"<<endl;
                        cout<<"1. Fitxer amb les meves cançons"<<endl;
                        cout<<"2. Afegir canco"<<endl;
                        cout<<"3. Eliminar totes les dades de la llista"<<endl;
                        cout<<"4. Sortir"<<endl;
                        cin>>opc3;
                        if(opc3>=1 && opc3<=4){
                            switch(opc3){
                                case 1:
                                    sortida_fitxer(mi_lista, dates);
                                    break;
                                case 2:
                                    afegir(mi_lista, playlist);
                                    break;
                                case 3:
                                    mi_lista.clear();
                                    break;
                                case 4:
                                    cout<<"Tornant al menú principal..."<<endl;
                                    continuar2=false;
                                    break;
                                default:;
                            }
                        }
                        else{
                            cout<<"Opcio incorrecte"<<endl;
                        }
                    }
                    break;
                case 3:
                    cout<<endl<<"GRACIES PER UTILITZAR EL NOSTRE PROGRAMA, ESPEREM QUE LI HAGI AGRADAT"<<endl;
                    cout<<"Sara & Oriol"<<endl;
                    continuar=false;
                    break;
                default:;
            }
        }
        else{cout<<"Opcio incorrecte"<<endl;}
    }
}

//FUNCIONES

bool coincidir(vector<char> &cantante, vector<char> &autor){
    //Per tal de poder tenir en compte alguna falta d'ortografia afegim comptadors
    int i, compt=0, compti=0;
    long int dim=cantante.size();
    for(i=0;i<dim;i++){
        compt++;
        if(cantante[i]==autor[i]){
            compti++;
        }
    }
    if((compt-compti)<1){
        return true;
    }
    else{return false;}
}

void logo(char x){
    cout<<"xxx xx   x xxxxx  xx        xx   xx x  x xxxxx x  xxxx"<<endl;
    cout<<" x  x x  x x     x  x       x x x x x  x x     x x"<<endl;
    cout<<" x  x  x x xxx  x    x  xx  x  x  x x  x xxxxx x x"<<endl;
    cout<<" x  x   xx x     x  x       x     x x  x     x x x"<<endl;
    cout<<"xxx x    x x      xx        x     x  xx  xxxxx x  xxxx"<<endl;
}

void llegir_dades(vector<lista> &playlist){
    ifstream dades("BaseDeDatos.txt");
    lista l;
    char c;
    while(dades>>c){
        while(c!='-'){
            l.cantante.push_back(c);
            dades.get(c);
        }
        //Eliminem l'ultim espai
        l.cantante.pop_back();
        dades.get(c);
        if(c==' '){
            dades.get(c);
        }
        while(c!='-'){
            l.cancion.push_back(c);
            dades.get(c);
        }
        //Eliminem l'ultim espai
        l.cancion.pop_back();
        dades>>l.any;
        //por el ‘-’ que separa año y género en los datos
        dades>>c;
        dades>>l.genero;
        playlist.push_back(l);
        //para que no se acumulen los caracteres
        l.cantante.clear();
        l.cancion.clear();
    }
}

void llegir_llista(vector<lista> &mi_lista, vector<data> &dates){
    ifstream milista("MiLista.txt");
    lista l;
    data d;
    char c;
    while(milista>>c){
        while(c!='-'){
            l.cantante.push_back(c);
            milista.get(c);
        }
        l.cantante.pop_back();
        milista.get(c);
        if(c==' '){
            milista.get(c);
        }
        while(c!='-'){
            l.cancion.push_back(c);
            milista.get(c);
        }
        l.cancion.pop_back();
        milista>>l.any;
        //por el ‘-’ que separa año y género en los datos
        milista>>c;
        milista>>l.genero;
        mi_lista.push_back(l);
        //para que no se acumulen los caracteres
        l.cantante.clear();
        l.cancion.clear();
        milista>>d.dia;
        milista>>d.mes;
        milista>>d.any;
        dates.push_back(d);
    }
}

void sortida_fitxer(vector<lista> &mi_lista, vector<data> &dates){
    ofstream milista("MiLista.txt");
    int i,a;
    long int dim=mi_lista.size(), dimcant, dimcanc;
    //Ho escribim de la mateixa manera que com entren les dades desde el fitxer
    for(i=0;i<dim;i++){
        dimcant=mi_lista[i].cantante.size();
        dimcanc=mi_lista[i].cancion.size();
        for(a=0;a<dimcant;a++){
            milista<<mi_lista[i].cantante[a];
        }
        milista<<"- ";
        for(a=0;a<dimcanc;a++){
            milista<<mi_lista[i].cancion[a];
        }
        milista<<"- "<<mi_lista[i].any<<" - "<<mi_lista[i].genero<<' '<<dates[i].dia<<' '<<dates[i].mes<<' '<<dates[i].any<<endl;
    }
}

void escribir_info(vector<lista> &playlist, int i){
    int a;
    long int dimcant=playlist[i].cantante.size(), dimcanc=playlist[i].cancion.size();
    cout<<endl<<"Autor: ";
    for(a=0;a<dimcant;a++){
        cout<<playlist[i].cantante[a];
    }
    cout<<endl<<"Canco: ";
    for(a=0;a<dimcanc;a++){
        cout<<playlist[i].cancion[a];
    }
    cout<<endl<<"Any: "<<playlist[i].any<<endl;
    cout<<"Genere: "<<playlist[i].genero<<endl<<endl;
}

void afegir(vector<lista> &mi_lista, vector<lista> &playlist){
    lista l;
    char c;
    cout<<"Omple les següents opcions"<<endl;
    cout<<"Autor: (acabat en punt) ";
    cin.get(c);
    while(c!='.'){
        l.cantante.push_back(c);
        cin.get(c);
    }
    cout<<"Canco: (acabada en punt) ";
    cin.get(c);
    while(c!='.'){
        l.cancion.push_back(c);
        cin.get(c);
    }
    cout<<"Any: ";
    cin>>l.any;
    cout<<"Genere: ";
    cin>>l.genero;
    mi_lista.push_back(l);
    playlist.push_back(l);
    cout<<"La canco ha estat afegida"<<endl;
}

void modificar(vector<lista> &mi_lista, vector<data> &dates, int i, data d){
    mi_lista[i].cantante.clear();
    mi_lista[i].cancion.clear();
    char c;
    cout<<"Omple les opcions següents"<<endl;
    cout<<"Autor: (acabat en punt) ";
    cin.get(c);
    while(c!='.'){
        mi_lista[i].cantante.push_back(c);
        cin.get(c);
    }
    cout<<"Canco: (acabat en punt)";
    cin.get(c);
    while(c!='.'){
        mi_lista[i].cancion.push_back(c);
        cin.get(c);
    }
    cout<<"Any: ";
    cin>>mi_lista[i].any;
    cout<<"Genere: ";
    cin>>mi_lista[i].genero;
    //Finalment canviem la data a la d'avui per tal de que quedi reflexat el dia que s'ha modificat
    dates[i].dia=d.dia;
    dates[i].mes=d.mes;
    dates[i].any=d.any;
    cout<<"La canco ha estat modificada"<<endl;
}

void eliminar(vector<lista> &mi_lista, vector<data> &dates, int i){
    int a;
    lista l;
    data d;
    long int dim=mi_lista.size();
    d=dates[i];
    l=mi_lista[i];
    //Guardem les dades que volem eliminar i movem totes les dades posteriors una casella endavant.
    for(a=i;a<dim-1;a++){
        mi_lista[a]=mi_lista[a+1];
        dates[a]=dates[a+1];
    }
    //Guardem a l'ultima posicio les dades a eliminar i fem un pop_back
    mi_lista[dim-1]=l;
    dates[dim-1]=d;
    mi_lista.pop_back();
    dates.pop_back();
    cout<<"La canco ha estat eliminada"<<endl;
}

void recomendacion(vector<lista> &playlist, vector<lista> &mi_lista, lista busquedes){
    int i=0, a=0;
    bool trobat=false;
    long int dimp=playlist.size(), diml=mi_lista.size();
    while(i<dimp && !trobat){
        if(playlist[i].genero==busquedes.genero){
            //Com que volem que no sigui la meteixa canço li diem que no sigui igual
            if(playlist[i].any!=busquedes.any){
                //Com que tampoc volem que sigui a la llista, la busquem i si no es troba l'haurem trobada
                while(a<diml && !trobat){
                    if(!coincidir(playlist[i].cancion,mi_lista[a].cancion)){
                        trobat=true;
                    }
                    else{a++;}
                }
            }
        }
        else{
            i++;
        }
    }
    if(trobat){
        cout<<endl<<"Creiem que et podria agradar: "<<endl;
        escribir_info(playlist,i);
    }
    else{
        cout<<"Encara no tenim cap recomanació per a tu en aquest moment."<<endl;
    }
}

void busqueda(vector <lista> &playlist, vector<lista> &busquedes, vector<int> &ni){
    busquedes.clear();
    ni.clear();
    int opc3, i=0, compt=0, any;
    char c;
    string genere;
    long int dim=playlist.size();
    bool trobat=false;
    vector<char> autor, canco;
    cout<<endl<<"MENU DE BUSQUEDA"<<endl;
    cout<<"1. Per autoria"<<endl;
    cout<<"2. Per canco"<<endl;
    cout<<"3. Per any de publicació"<<endl;
    cout<<"4. Per genere"<<endl;
    cout<<"5. Sortir"<<endl;
    cin>>opc3;
    if(opc3>=1 &&opc3<=5){
        switch(opc3){
            case 1:
                cout<<endl<<"Nom de l’autor: (Acabat en punt) "<<endl;
                cin>>c;
                while(c!='.'){
                    autor.push_back(c);
                    cin.get(c);
                }
                while(i<dim){
                    if(coincidir(playlist[i].cantante, autor)){
                        compt++;
                        cout<<endl<<compt<<'.';
                        escribir_info(playlist,i);
                        busquedes.push_back(playlist[i]);
                        ni.push_back(i);
                    }
                    i++;
                }
                if(compt==0){
                    cout<<"No s'ha trobat cap resultat"<<endl;
                }
                break;
            case 2:
                cout<<endl<<"Nom de la canco: (Acabat en punt)"<<endl;
                cin>>c;
                while(c!='.'){
                    canco.push_back(c);
                    cin.get(c);
                }
                while(i<dim && !trobat){
                    if(coincidir(playlist[i].cancion, canco)){
                        trobat=true;
                    }
                    else{i++;}
                }
                if(trobat){
                    escribir_info(playlist, i);
                    busquedes.push_back(playlist[i]);
                }
                else{cout<<"No s'ha trobat cap resultat"<<endl;}
                break;
            case 3:
                cout<<endl<<"Any de publicació: ";
                cin>>any;
                for(i=0;i<dim;i++){
                    if(playlist[i].any==any){
                        compt++;
                        cout<<endl<<compt<<'.';
                        escribir_info(playlist,i);
                        busquedes.push_back(playlist[i]);
                        ni.push_back(i);
                    }
                }
                if(compt==0){
                    cout<<"No s'ha trobat cap resultat"<<endl;
                }
                break;
            case 4:
                cout<<endl<<"Genere de la canco: ";
                cin>>genere;
                for(i=0;i<dim;i++){
                    if(playlist[i].genero==genere){
                        compt++;
                        cout<<endl<<compt<<'.';
                        escribir_info(playlist,i);
                        busquedes.push_back(playlist[i]);
                        ni.push_back(i);
                    }
                    i++;
                }
                if(compt==0){
                    cout<<"No s'ha trobat cap resultat"<<endl;
                }
                break;
            case 5:
                cout<<endl<<"Tornant al menú de busqueda..."<<endl;
                break;
                default:;
        }
    }
}

void opciones(vector <lista> &playlist, vector<lista> &mi_lista, vector<lista> &busquedes, vector<data> &dates, vector<int> &ni, int opc, data d){
    int opc2, i=0,num;
    bool trobat=false;
    long int dim=busquedes.size(), diml=mi_lista.size(), dimi=ni.size();
    if(opc==1){
        cout<<endl<<"MENU D'OPCIONS"<<endl;
        cout<<"1. Afegir a la meva llista"<<endl;
        cout<<"2. Recomanar canco"<<endl;
        cout<<"3. Sortir"<<endl;
        cin>>opc2;
        if(opc2>=1 &&opc2<=3){
            switch(opc2){
                case 1:
                    if(dim>1){
                        cout<<endl<<"Quina canco vols afegir?"<<endl;
                        cin>>num;
                        while(num!=0 && num<dim){
                            while(i<diml && !trobat){
                                if(coincidir(mi_lista[i].cancion, busquedes[num-1].cancion)){
                                    trobat=true;
                                }
                                else{i++;}
                            }
                            if(!trobat){
                                mi_lista.push_back(playlist[i]);
                                dates.push_back(d);
                                cout<<"La teva canco ha estat afegida"<<endl;
                            }
                            else{cout<<"La canco ja es troba a la teva llista"<<endl;}
                            cout<<"Quina canco vols afegir? (Si ja no vols afegir cap canco més posa 0)"<<endl;
                            cin>>num;
                        }
                    }
                    else{
                        while(i<diml && !trobat){
                            if(coincidir(mi_lista[i].cancion, busquedes[0].cancion)){
                                trobat=true;
                            }
                            else{i++;}
                        }
                        if(!trobat){
                            mi_lista.push_back(playlist[i]);
                            dates.push_back(d);
                            cout<<"La teva canco ha estat afegida"<<endl;
                        }
                        else{cout<<"La canco ja es troba a la teva llista"<<endl;}
                    }
                    break;
                case 2:
                    recomendacion(playlist, mi_lista, busquedes[dim-1]);
                    break;
                case 3:
                    break;
                default:;
            }
        }
        else{cout<<"Opcio incorrecte"<<endl;}
    }
    else{
        cout<<endl<<"MENU D'OPCIONS"<<endl;
        cout<<"1. Modificar"<<endl;
        cout<<"2. Eliminar"<<endl;
        cout<<"3. Sortir"<<endl;
        cin>>opc2;
        if(opc2>=1 &&opc2<=3){
            switch(opc2){
                case 1:
                    if(dimi>1){
                        cout<<endl<<"Quina canco vols modificar"<<endl;
                        cin>>num;
                        while(num!=0 && num<dim){
                            modificar(mi_lista, dates, ni[num-1], d);
                            cout<<"Quina canco vols modificar (Si ja no vols modificar cap canco més posa 0)"<<endl;
                            cin>>num;
                        }
                    }
                    else{modificar(mi_lista, dates, ni[0],d);}
                    break;
                case 2:
                    if(dimi>1){
                        cout<<endl<<"Quina canco vols eliminar"<<endl;
                        cin>>num;
                        while(num!=0 && num<dim){
                            eliminar(mi_lista, dates, ni[num-1]);
                            cout<<"Quina canco vols eliminar (Si ja no vols eliminar cap canco més posa 0)"<<endl;
                            cin>>num;
                        }
                    }
                    else{eliminar(mi_lista, dates, ni[0]);}
                    break;
                case 3:
                    break;
                default:;
            }
        }
        else{cout<<"Opcio incorrecte"<<endl;}
    }
}
