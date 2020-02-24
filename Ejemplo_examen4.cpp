#include <iostream>
using namespace std;
const int NomSort=3;
int main(){
    float h,w,Wid,oro;
    char complexio,sexe;
    cout<<"Indica la teva alcada, el teu pes, la teva complexio (R,P,N) i el teu sexe (H,D): "<<endl;
    cin>>h>>w>>complexio>>sexe;
    if (1.12<(h/w)<3.80 && (sexe=='D'||sexe=='H')){
        if (sexe=='D'){
            Wid=45.35+((h-152.4)/2.54)*2.267;}
        else{
            Wid=48.08+((h-152.4)/2.54)*2.720;}

        if (complexio=='R'){
            Wid+=Wid*0.1;}
        else{if(complexio=='P'){
                Wid-=Wid*0.1;}
            else{Wid=Wid;}}

        if((w-Wid)<=1){
            oro=1;}
        else{oro=1/(w-Wid);}

        if(int(Wid)%NomSort==0){
            oro*=2;}
        else{oro/=NomSort;}

        cout<<"El premi del SEU PES EN OR es: "<<oro<<"kg"<<endl;
    }
    else{cout<<"Dades fora de rang"<<endl;}
}
