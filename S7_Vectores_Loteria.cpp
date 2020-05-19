///Obtienen un premio especial las parejas de octogenarios que tienen números de lotería consecutivos.
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void notifica_premio(vector<string>& emails);

int main(){
    ifstream fin("numeros.txt");
    vector<string> emails;
    string email1, email2;
    int numero, edad1, edad2;
    fin>>email1>>numero>>edad1;
    while(!fin.eof()){
        fin>>email2>>numero>>edad2;
        if(edad1>=80){
            if(edad2>=80){
                emails.push_back(email1);
                emails.push_back(email2);
            }
        }
        email1=email2; edad1=edad2;
    }
    notifica_premio(emails);
}

void notifica_premio(vector<string>& emails){
    int i, dim=emails.size();
    for(i=0;i<dim;i++){
        cout<<emails[i];
    }
}
