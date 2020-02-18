#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a,b,c,sol1,sol2,raiz;
    cout<<"Indica els tres coeficients de la teva equacio de segon grau: ";
    cin>>a>>b>>c;
    if(a==0){
        sol1=-(c/b);
        cout<<"x="<<sol1<<endl;
    }
    else{
        raiz=sqrt(((b*b)-(4*a*c)));
        if(raiz>=0){
            sol1=((-b)+raiz)/(2*a);
            sol2=((-b)-raiz)/(2*a);
            if (sol1==sol2){
                cout<<"x="<<sol1<<endl;
            }
            else{
                cout<<"x1="<<sol1<<endl;
                cout<<"x2="<<sol2<<endl;
            }
        }
        else{
            cout<<"La solucio no es real"<<endl;
        }
    }
}
