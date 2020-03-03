#include <iostream>
using namespace std;
int main(){
    int num,prod=1;
    cout<<"Indica el numero del que vols calcular el factorial: "<<endl;
    cin>>num;
    while(num!=0){
        prod*=num;
        num--;
    }
    cout<<"El factorial del teu nombre es: "<<prod<<endl;
}
