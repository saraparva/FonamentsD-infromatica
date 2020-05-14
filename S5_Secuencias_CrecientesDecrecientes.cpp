#include <iostream>
using namespace std;
int main(){
    int antecesor, num, sucesor, comptCreciente=0, comptDecreciente=0;
    cout<<"Introduce una secuencia de numeros acabada en zero."<<endl;
    cin>>antecesor>>num;
    if(antecesor!=0 && num!=0){
        cin>>sucesor;
        while (sucesor!=0){
            if (antecesor<num && num<sucesor){
                comptCreciente++;
            }
            else{
                if (antecesor>num && num>sucesor){
                    comptDecreciente++;
                }
            }
            antecesor=num;
            num=sucesor;
            cin>>sucesor;
        }
        cout<<"La secuencia introducida contiene "<<comptCreciente<<" subsecuencias crecientes y "<<comptDecreciente<<" decrecientes."<<endl;
    }
    else{
        cout<<"No hi ha cap sequencia de nombres introduida."<<endl;
    }
}
