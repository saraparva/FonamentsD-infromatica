#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Introdueix un nombre natural: ";
    cin>>num;
    if (num!=0){
            if (num%2==0){
                cout<<"Es un nombre parell."<<endl;
            }
            else{
                cout<<"Es un nombre senar."<<endl;
            }
    }
    else{
        cout<<"El teu nombre es el zero."<<endl;
    }
}
