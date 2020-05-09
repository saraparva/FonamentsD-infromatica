#include <iostream>
using namespace std;
int main(){
    float x, y, x1, y1, x2, y2, m, n;
    bool trobat=false;
    cout<<"Introdueix una secuencia de punts 2D."<<endl;
    cin>>x1>>y1;
    if (x1!=-1 && y1!=-1){
        cin>>x2>>y2;
        if (x2!=-1 && y2!=-1){
            m=(y1-y2)/(x1-x2);
            n=y1-(m*x1);
            cin>>x>>y;
            while ((x!=-1 && y!=-1) && trobat){
                if (m*x+n!=y){
                    trobat=true;
                }
                else{
                    cin>>x>>y;
                }
            }
            if (trobat){
                cout<<"Tots els punts no son colineals."<<endl;
            }
            else{
                cout<<"Tots els punts son lineals."<<endl;
            }
        }
        else{
            cout<<"Nomes s'ha introduit un punt."<<endl;
        }
    }
    else{
        cout<<"No hi ha cap sequencia de punts introduida."<<endl;
    }
}
