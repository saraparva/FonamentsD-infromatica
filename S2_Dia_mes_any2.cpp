#include <iostream>
using namespace std;
int main(){
    int data,dia,mes,any;
    string MES;
    cout<<"Itrodueaix el dia més i l'any en el format (DDMMAAAA):";
    cin>>data;
    dia=data/1000000;
    mes=(data/10000)%100;
    any=data%10000;
    cout<<"Dia: "<<dia<<endl;
    cout<<"Mes: "<<mes<<endl;
    cout<<"Any: "<<any<<endl;
    if (mes==1){MES="Gener";}
    else{if(mes==2){MES="Febrer";}
        else{if(mes==3){MES="Març";}
            else{if(mes==4){MES="Abril";}
                else{if(mes==5){MES="Maig";}
                    else{if(mes==6){MES="Juny";}
                        else{if(mes==7){MES="Juliol";}
                            else{if(mes==8){MES="Agost";}
                                else{if(mes==9){MES="Septembre";}
                                    else{if(mes==10){MES="Octubre";}
                                        else{if(mes==11){MES="Nobembre";}
                                            else{if(mes==12){MES="Desembre";}
    }}}}}}}}}}}
    cout<<"La data es: "<<dia<<" de "<<MES<<" de "<<any<<endl;
}

