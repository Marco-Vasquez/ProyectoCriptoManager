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
};

#endif // CIFRADORVIGENERE_H
