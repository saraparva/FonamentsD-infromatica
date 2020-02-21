#include <iostream>
using namespace std;
int main(){
    int dia,mes,any;
    string MES;
    cout<<"Itrodueaix el dia més i l'any en el format (dia-mes-any):";
    cin>>dia>>mes>>any;
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
