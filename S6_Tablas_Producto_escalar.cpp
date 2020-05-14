#include <stdio.h>
#include <iostream>
using namespace std;
const int N=10;

void llegir_vector(int n, float v[N]);

int main(){
    float v1[N], v2[N], producte;
    int num_elements, i;
    cout<<"Introdueix el numero d'elements dels vectors."<<endl;
    cin>>num_elements;
    if(num_elements<=N){
        llegir_vector(num_elements,v1);
        llegir_vector(num_elements,v2);
        producte=0;
        for(i=0;i<num_elements;i++){
            producte+=v1[i]*v2[i];
        }
        cout<<"El producte dels dos vectors introduits es: "<<producte<<endl;
    }
    else{
        cout<<"La dimensio introduida no es valida."<<endl;
    }
}

void llegir_vector(int n, float v[N]){
    int i;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
}
