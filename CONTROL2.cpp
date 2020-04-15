///*****************************************************************************************************
//
///    ES OBLIGATORIO LLENAR LA INFORMACION QUE SE SOLICITA A CONTINUACIÓN
///
///                                    CONTROL 2 -- 15 DE MAYO
//
///    NOMBRE: SARA PARDO VALERO
///    DNI: 53644881A
///    GRADO: GREFI
///    GRUPO: 23
//
///    FASE 3
//
//

///*****************************************************************************************************
///                                          BIBLIOTECAS
///*****************************************************************************************************

#include <iostream>
#include <fstream>
using namespace std;

///*****************************************************************************************************
///                                      CONSTANTES, SI SE DECLARAN
///*****************************************************************************************************

//const . . . .

///*****************************************************************************************************
///                             SUBPROGRAMAS, O EN SU CASO, ENCABEZADOS (PROTOTIPOS)
///*****************************************************************************************************

void estada_parking (int arribada, int sortida, int &h, int &m, float &preu);

///*****************************************************************************************************
///                                          PROGRAMA PRINCIPAL
///*****************************************************************************************************

int main(){
    int arribada, sortida, hores, minuts,i=1,cocheMin,cocheMax,pagoMin,pagoMax=0;
    float preu,recaudacio=0;
    string mot_a,mot_s;
    ifstream fin("cotxes.txt");
    ofstream fot("parking.txt");
    while(fin>>arribada>>mot_a>>sortida>>mot_s){
        preu=0;
        if(mot_a=="pm"){
            arribada+=1200;
        }
        if(mot_s=="pm"){
            sortida+=1200;
        }
        estada_parking(arribada,sortida,hores,minuts,preu);
        fot<<"Coche "<<i<<" - Tiempo de parking "<<hores<<" horas y "<<minuts<<" minutos, a pagar: "<<preu<<" euros."<<endl;
        i++;
        recaudacio+=preu;
    }
    fot<<"La recaudacion del dia, de "<<i<<" coches, ha sido: "<<recaudacio<<" euros."<<endl;
}
///*****************************************************************************************************
///               DESARROLLO DE SUBPROGRAMAS SI SE OPTÓ POR HACER ENCABEZADOS O PROTOTIPOS
///*****************************************************************************************************

void estada_parking (int arribada, int sortida, int &h, int &m, float &preu){
    int temps_estada,temps,H;
    temps_estada=sortida-arribada;
    m=temps_estada%100;
    h=temps_estada/100;
    temps=h*60+m;
    if (temps>=30){
        preu+=30*0.1;
        temps-=30;
    }
    else{
        preu+=temps*0.1;
    }
    preu+=temps*0.05;
    preu-=h*0.5;
}
