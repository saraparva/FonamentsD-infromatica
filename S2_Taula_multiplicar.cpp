#include <iostream>
using namespace std;
int main(){
    int num,i,por;
    cout<<"Indica el numero (entre el 1 i el 10) de la taula de multiplicar que vols veure: "<<endl;
    cin>>num;
    if (num>=1 && num<=10){
        for (i=1;i<=10;i++){
            por=num*i;
            cout<<num<<'x'<<i<<'='<<por<<endl;
        }
    }
    else{
        cout<<"ERROR, el nombre ha de estar entre 1 i 10."<<endl;
    }
}
