// donats la velocitat mitjana d’un cotxe i la distància a recórrer es calcula el temps que trigarà a fer-la.
#include <iostream>
using namespace std;
int main(){
    int v,d;
    float t;
    cout<<"Quina es la teva velocitat mitjana? (Unitats:m/s^2) "<<endl;
    cin>>v;
    cout<<"Quina distancia has de recorrer? (Unitats:m) "<<endl;
    cin>>d;
    //d=v*t
    //t=d/v
    t=float(d)/v;
    //1 hora=3600 segundos
    if (t>3600){
        t/=3600;
        cout<<"Trigaras "<<t<<" hores"<<endl;
    }
    else{if (t>60){
            t/=60;
            cout<<"Trigaras "<<t<<" minuts"<<endl;
        }
        else{
            cout<<"Trigaras "<<t<<" segons"<<endl;
        }
    }
}
