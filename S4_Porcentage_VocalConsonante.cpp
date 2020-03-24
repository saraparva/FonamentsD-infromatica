#include <iostream>
using namespace std;

void comptarVocalsConsonants (char c, int& nVocals, int& nConsonants){
    bool vocal,consonante;
    vocal=(c=='A'|| c=='E'|| c=='I'|| c=='O'|| c=='U'||c=='a'|| c=='e'|| c=='i'||c=='o'||c=='u');
    consonante=((c>=65 && c<=90)||(c>=97 && c<=122));
    if(vocal){
        nVocals++;
    }
    else{
        if(consonante){
            nConsonants++;
        }
    }
}

int main(){
    int nVocals=0,nConsonants=0,lletres=0;
    float pVocals, pConsonants;
    char texto;
    cout<<"Escriu una frase acabada en '.':"<<endl;
    texto=cin.get();
    while (texto!='.'){
        if (texto!=' '){
            comptarVocalsConsonants(texto,nVocals,nConsonants);
            lletres++;
            texto=cin.get();
        }
        else{
            texto=cin.get();}
    }
    if(nVocals==0 && nConsonants==0){
        cout<<"No hi ha lletres en la frase"<<endl;
    }
    else{
        pVocals=(float(nVocals)/lletres)*100;
        pConsonants=(float(nConsonants)/lletres)*100;
        cout<<"Hi ha "<<nVocals<<" vocals."<<endl;
        cout<<"Hi ha "<<nConsonants<<" consonants."<<endl;
        cout<<"El percentatge de vocals que hi ha a la frase es de "<<pVocals<<" % i el percentatge de consonants es de "<<pConsonants<<" %."<<endl;
    }

}
