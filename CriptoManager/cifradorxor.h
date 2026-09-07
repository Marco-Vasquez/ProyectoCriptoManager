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
};

#endif // CIFRADORXOR_H
