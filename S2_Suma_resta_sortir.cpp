#include <iostream>
using namespace std;
int main(){
    float a,b,result;
    int opc;
    cout<<"MENU D'OPCIONS"<<endl;
    cout<<"1.Suma"<<endl;
    cout<<"2.Resta"<<endl;
    cout<<"3.Sortir"<<endl;
    cout<<"Seleccoineu una opció:"<<endl;
    cin>>opc;
    switch(opc){
        case 1:
            cout<<"Escriu els operants: ";
            cin>>a>>b;
            result=a+b;
            cout<<"El resultat de la suma es: "<<result<<endl;
            break;
        case 2:
            cout<<"Escriu els operants: ";
            cin>>a>>b;
            result=a-b;
            cout<<"El resultat de la resta es: "<<result<<endl;
            break;
        case 3:
            cout<<"BYE BYE"<<endl;
            break;
        default:;
    }
    system("pause");
}
