#include "cifradorxor.h"

CifradorXOR::CifradorXOR(string claveSecreta):Cifrador("XOR") {
    clave=claveSecreta;
}
CifradorXOR::~CifradorXOR(){}
string CifradorXOR::cifrar(string texto){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char caracterClave=clave[i%longitudClave];
        resultado+=char(texto[i]^caracterClave);
    }
    return resultado;
}
string CifradorXOR::descifrar(string texto){
    return cifrar(texto);
}
