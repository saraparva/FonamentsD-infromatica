#include <iostream>
using namespace std;
int main(){
    int num,i;
    cout<<"Indica el numero (entre el 1 i el 10) de la taula de multiplicar que vols veure: "<<endl;
    cin>>num;
    if (num>=1 && num<=10){
        for (i=1;i<=10;i++){
            cout<<num<<'x'<<i<<'='<<num*i<<endl;
        }
    }
    else{
        cout<<"ERROR, el nombre ha de estar entre 1 i 10."<<endl;
    }
}
