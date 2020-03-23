#include <iostream>
#include <math.h>
using namespace std;

int val_absolut(float x){
    if (x<0){
        x=-x;
    }
    return x;
}

bool son_paraleles(float A1, float B1, float C1, float A2, float B2, float C2, float x, float y){
    float suma;
    if ((A1/A2)==(B1/B2)){
        suma=A2*x+B2*y+C2;
        if (suma==0){
            return false;}
        else{ return true;}
    }
    else{ return false;}
}

float distancia(float A, float B, float C, float x, float y){
    float suma,D;
    suma=A*x+B*y+C;
    D=val_absolut(suma)/sqrt(pow(A,2)+pow(B,2));
    return D;
}

int main(){
    float A1,B1,C1,A2,B2,C2,X,Y;
    bool paraleles;
    cout<<"Escriu la primera funcio d'una recta tipus Ax+By+C=0 (escriu A B C): ";
    cin>>A1>>B1>>C1;
    cout<<"Escriu la segona funcio d'una recta tipus Ax+By+C=0 (escriu A B C): ";
    cin>>A2>>B2>>C2;
    if(B1!=0){
        X=0
        Y=-C1/B1;
    }
    else{
        X=-C1/A1;
        Y=0;
    }
    paraleles=son_paraleles(A1,B1,C1,A2,B2,C2,X,Y)
    if (paraleles){
        cout<<"Les dos rectes son paraleles"<<endl;
        cout<<"La distancia entre les dues rectes es: "<<distancia(A2,B2,C2,X,Y)<<endl;
    }
    else{
        cout<<"Les dos rectes donades no son paraleles"<<endl;
    }
}

