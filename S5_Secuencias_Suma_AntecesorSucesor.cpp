#include <iostream>
using namespace std;
int main (){
    int antecesor, num, sucesor;
    bool trobat=false;
    cout<<"Introdueix una sequencia de nombres acabada en zero."<<endl;
    cin>>antecesor; cin>>num;
    if (antecesor!=0 && num!=0){
        cin>>sucesor;
        while (sucesor!=0 && !trobat){
            if (antecesor+sucesor==num){
                trobat=true;
            }
            else{
                antecesor=num;
                num=sucesor;
                cin>>sucesor;
            }
        }
        if (trobat){
            cout<<"El nombre que cumpleix la condicio es el "<<num<<". El seu antesesor es el "<<antecesor<<" i el seu sucesor es el "<<sucesor<<endl;
        }
        else{
            cout<<"No s'ha trobat cap nombre que cumpleixi la condicio."<<endl;
        }
    }
    else{
        cout<<"No hi ha cap sequencia de nombres introduida."<<endl;
    }
}
