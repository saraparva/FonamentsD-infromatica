// Nom: Sara Pardo Valero
// DNI: 53644881A

#include <iostream>
#include <fstream>
using namespace std;

void codigo (char let1, char let2, bool &consonante, bool &mayuscula);

int main(){
    char let1, let2, let1F, let2F, let1E, let2E;
    int num1, num2;
    int fresco=0, envasado=0;
    int compt_deposito=0, compt_reponer=0, max_fresco=0, max_envasado=0;
    ifstream cinF("inventario.txt");
    ofstream cout1("InventarioFrescos.txt");
    ofstream cout2("InventarioEnvasados.txt");
    ofstream cout3("ReposicionFrescos.txt");
    ofstream cout4("ReposicionEnvasados.txt");
    while(let1=cinF.get()){
        let2=cinF.get();
        cinF>>num1>>num2;
        bool consonante=true, mayuscula, existe=false;
        codigo(let1,let2,consonante,mayuscula);
        if(consonante){
            if(mayuscula){
                cout1<<let1<<let2<<' '<<num1<<' '<<num2<<endl;
                compt_deposito++;
                if(num2>max_fresco){
                    let1E=let1;
                    let2E=let2;
                }
            }
            else{
                cout4<<let1<<let2<<' '<<num1<<' '<<num2<<endl;
                compt_reponer++;
            }
        }
        else{
            if(mayuscula){
                cout2<<let1<<let2<<' '<<num1<<' '<<num2<<endl;
                compt_deposito++;
                if(num2>max_envasado){
                    let1F=let1;
                    let2F=let2;
                }
            }
            else{
                cout3<<let1<<let2<<' '<<num1<<' '<<num2<<endl;
                compt_reponer++;
            }
        }
    }
    cout<<"La quantitat total de productes que hi ha al depósit es: "<<compt_deposito<<endl;
    cout<<"La quantitat total de productes que s'han de repostar es: "<<compt_reponer<<endl;
    cout<<"El codi de productes frescs en mayor quantitat es: "<<let1F<<let2F<<endl;
    cout<<"El codi de productes envasats en mayor quantitat es: "<<let1E<<let2E<<endl;
}

void codigo (char let1, char let2, bool &consonante, bool &mayuscula){
    switch (let1) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        consonante = false;
        break;
    }
    if(let2<='A' && let2>='Z'){ mayuscula=true;}
    else{ mayuscula=false;}
}
