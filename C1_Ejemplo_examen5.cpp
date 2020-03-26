#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float i,TAE;
    int n;
    cout<<"Indica la taxa d'interes anual (percentatge) i el nombre de pagaments: ";
    cin>>i>>n;
    i/=100;
    if(i>0 && i<0.15 && n>0 && n<300){
        TAE=(pow((1+i/n),n)-1)*100;
        cout<<"Amb un interes anual de un "<<i*100<<" % i un nombre de pagaments igual a "<<n<<". Tindras una TAE igual a "<<TAE<<endl;
    }
    else{if(i<0 || i>0.15){
            cout<<"La taxa d'interes anual no es valida."<<endl;}
        if(n<0 || n>300){
            cout<<"El nombre de pagaments no es valid."<<endl;}
    }
}
