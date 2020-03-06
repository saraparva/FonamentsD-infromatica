#include <iostream>
using namespace std;
int main(){
    string codi;
    cout<<"Introdueix el codi:"<<endl;
    cin>>codi;
    while(codi!="fin"){
        cout<<"Codi: "<<codi<<endl;
        cin>>codi;
    }
    system("pause");
}
