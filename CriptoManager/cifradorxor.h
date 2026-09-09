#ifndef CIFRADORXOR_H
#define CIFRADORXOR_H
#include "Cifrador.h"
class CifradorXOR:public Cifrador
{
private:
    string clave;
public:
    CifradorXOR(string claveSecreta);
    ~CifradorXOR();
    string cifrar(string texto);
    string descifrar(string texto);
    char cifrarByte(unsigned char byte,int posicion);
    char descifrarByte(unsigned char byte,int posicion);
};

#endif // CIFRADORXOR_H
