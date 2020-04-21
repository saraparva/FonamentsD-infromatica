#include <iostream>
using namespace std;

void max_min (int num, int &max, int &min);
bool Tau (int num);

int main(){
    int i, a, b, num, max, min;
    cout<<"Escriu els nombres d'un interval: ";
    cin>>a>>b;
    num=a;
    while (!Tau(num)){
        num++;
    }
    max=num; min=num;
    for(i=a;i<b+1;i++){
        if(Tau(i)){
            max_min(i,max,min);
        }
    }
    cout<<"Per al rang ["<<a<<','<<b<<"] els nombres Tau menor i major son "<<min<<" i "<<max<<'.'<<endl;
}

void max_min (int num, int &max, int &min){
    if (num>max){
        max=num;
    }
    else{if (num<min){
            min=num;
        }
    }
}

bool Tau (int num){
    int i=1, numdiv=0;
    while (i<=num){
        if (num%i==0){
            numdiv++;
            i++;
        }
        else{i++;}
    }
    if (num%numdiv==0){
        return true;
    }
    else{
        return false;
    }
}

