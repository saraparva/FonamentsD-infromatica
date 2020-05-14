#include <iostream>
using namespace std;
const int elements=10;
int main(){
    int taula[elements], cont=1, i;
    for (i=0;i<elements;i++){
        cin>>taula[i];
    }
    for (i=0;i<elements-1;i++){
        if (taula[elements-1]==taula[i]){
            cont++;
        }
    }
    cout<<"L'ultim element apareix: "<<cont<<" vegades."<<endl;
}
