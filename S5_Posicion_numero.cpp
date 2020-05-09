#include <iostream>
using namespace std;
int main(){
    int n, num, posicio=0;
    bool trobat=false;
    cout<<"Introdueix el nombre del que vols saber la posicio."<<endl;
    cin>>n;
    cout<<"Introdueix la sequencia de nombres acabada en zero."<<endl;
    cin>>num;
    if (num!=0){
        while (num!=0 && !trobat){
            posicio++;
            if(num==n){
                trobat=true;
            }
            else{
                cin>>num;
            }
        }
        if (trobat){
            cout<<"El nombre "<<n<<" es troba a la posicio "<<posicio<<" de la sequencia."<<endl;
        }
        else{
            cout<<"No s'ha trobat el nombre "<<n<<" a la sequencia intrduida."<<endl;
        }
    }
    else{
        cout<<"No hi ha cap sequencia de nombres introduida."<<endl;
    }
}
