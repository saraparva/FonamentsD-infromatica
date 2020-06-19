#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int F=7; const int C=5;

typedef int Matriz[F][C];

void Leer(Matriz & X, Matriz & R);
void Mostrar( Matriz & X);
void CalculoB(Matriz & A, Matriz & B);

int main(){
   int Res;
   Matriz A,B,R;
   Leer(A,R);
   Mostrar(A);
   CalculoB(A,B);
   cout<<endl;
   Mostrar(B);
   for(int f=0;f<F;f++){
       for (int c=0; c<C; c++){
           Res=R[f][c]-B[f][c];
       }
   }
   cout << endl << endl << "La suma resultado es: " << Res << endl;
}

void Leer(Matriz & X, Matriz & R){
    ifstream cinF ("Prueba.txt");
    for(int f=0;f<F;f++)
       for (int c=0; c<C; c++) cinF >> X[f][c];
    for(int f=0;f<F;f++)
       for (int c=0; c<C; c++) cinF >> R[f][c];
}

void Mostrar(Matriz & X){
    for(int f=0;f<F;f++){
       for (int c=0; c<C; c++) cout <<"\t" << X[f][c] ;
       cout << endl;}
}

void CalculoB(Matriz & A, Matriz & B){
    int f,c,sumaf, sumac;
    vector<int> sumafi, sumaco;
    ///Primer comencem sumant les columnes
    for(c=0;c<C;c++){
        sumac=0;
        for(f=0;f<F;f++){
            sumac+=A[f][c];
        }
        sumaco.push_back(sumac);
    }
    ///Ara sumem les files
    for(f=0;f<F;f++){
        sumaf=0;
        for(c=0;c<C;c++){
            sumaf+=A[f][c];
        }
        sumafi.push_back(sumaf);
    }
    //Finalment asignem els valors a la matriu B 
    for(f=0;f<F;f++){
        for(c=0;c<C;c++){
            B[f][c]=(sumafi[f]-A[f][c])+(sumaco[c]-A[f][c]);
        }
    }
}
