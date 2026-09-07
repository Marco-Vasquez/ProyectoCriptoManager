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
};

#endif // CIFRADORCESAR_H
