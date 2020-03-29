#include <iostream>
#include <iostream>
#include <fstream>
using namespace std;

int SumParells(int n);
int SumSenars (int n);

int main(){
    ifstream fi("Mod1C2.txt");
    int sump=0,sums=0,sumn=0,num;
    while(fi>>num){
        sumn++;
        if (SumParells(num)>SumSenars(num)){
            sump++;}
        else {
            sums++;}
    }
    cout<<(float(sums)/sumn)*100<<" %"<<endl;
}

int SumParells(int n){
    int sump=0;
    n/=10;
    while(n>0){
        sump+=n%10;
        n/=100;
    }
    return sump;
}

int SumSenars(int n){
    int sums=0;
    while(n>0){
        sums+=n%10;
        n/=100;
    }
    return sums;
}
