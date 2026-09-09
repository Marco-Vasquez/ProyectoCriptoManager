#ifndef CIFRADORVIGENERE_H
#define CIFRADORVIGENERE_H
#include "Cifrador.h"
class CifradorVigenere:public Cifrador
{
private:
        string clave;
public:
    CifradorVigenere(string claveSecreta);
    ~CifradorVigenere();
    string cifrar(string texto);
    string descifrar(string texto);
    char cifrarByte(unsigned char byte,int posicion);
    char descifrarByte(unsigned char byte,int posicion);
};

#endif // CIFRADORVIGENERE_H
