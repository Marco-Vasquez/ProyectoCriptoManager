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
char CifradorXOR::cifrarByte(unsigned char byte,int posicion){
    unsigned char byteClave=(unsigned char)clave[posicion%clave.length()];
    return (char)(byte^byteClave);
}
char CifradorXOR::descifrarByte(unsigned char byte, int posicion){
    return cifrarByte(byte,posicion);
}
