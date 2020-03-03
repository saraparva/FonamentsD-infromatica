#include <iostream>
using namespace std;
int main(){
    string moneda;
    float dinero,dinerof;
    cout<<"Introdueix una quantitat i la moneda que vol modificar (euros/dolars): ";
    cin>>dinero>>moneda;
    if (moneda=="euros"){
        dinerof=dinero*1.08;
        cout<<dinero<<" "<<moneda<<" en dolars son: "<<dinerof<<" dolars"<<endl;
    }
    else{
        dinerof=dinero*0.92;
        cout<<dinero<<" "<<moneda<<" en euros son: "<<dinerof<<" euros"<<endl;
    }

}
