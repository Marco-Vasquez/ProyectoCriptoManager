#include "cifradorvigenere.h"
#include <cctype>
CifradorVigenere::CifradorVigenere(string claveSecreta):Cifrador("Vigenere") {
    clave=claveSecreta;
}
CifradorVigenere::~CifradorVigenere(){}
string CifradorVigenere::cifrar(string texto){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        char caracterClave=clave[i%longitudClave];
        int valorClave=toupper(caracterClave)-'A';
        if(isupper(letra)){
            resultado+=char((letra-'A'+valorClave)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'+valorClave)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
string CifradorVigenere::descifrar(string texto){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        char caracterClave=clave[i%longitudClave];
        int valorClave=toupper(caracterClave)-'A';
        if(isupper(letra)){
            resultado+=char((letra-'A'-valorClave+26)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'-valorClave+26)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
char CifradorVigenere::cifrarByte(unsigned char byte,int posicion){
    unsigned char byteClave=(unsigned char)clave[posicion%clave.length()];
    return (char)((byte+byteClave)%256);
}
char CifradorVigenere::descifrarByte(unsigned char byte,int posicion){
    unsigned char byteClave=(unsigned char)clave[posicion%clave.length()];
    return (char)((byte-byteClave+256)%256);
}