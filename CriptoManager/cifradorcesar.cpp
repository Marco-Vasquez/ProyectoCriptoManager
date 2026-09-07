#include "cifradorcesar.h"
#include <cctype>
CifradorCesar::CifradorCesar(int claveDesplazamiento):Cifrador("Cesar") {
    clave=claveDesplazamiento%26;
}
CifradorCesar::~CifradorCesar(){}
string CifradorCesar::cifrar(string texto){
    string resultado="";
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        if(isupper(letra)){
            resultado+=char((letra-'A'+clave)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'+clave)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
string CifradorCesar::descifrar(string texto){
    string resultado="";
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        if(isupper(letra)){
            resultado+=char((letra-'A'-clave+26)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'-clave+26)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}