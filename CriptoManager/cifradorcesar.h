#ifndef CIFRADORCESAR_H
#define CIFRADORCESAR_H
#include "Cifrador.h"
class CifradorCesar:public Cifrador
{
private:
    int clave;
public:
    CifradorCesar(int claveDesplazamiento);
    ~CifradorCesar();
    string cifrar(string texto);
    string descifrar(string texto);
    char cifrarByte(unsigned char byte,int posicion);
    char descifrarByte(unsigned char byte,int posisicion);
};

#endif // CIFRADORCESAR_H
