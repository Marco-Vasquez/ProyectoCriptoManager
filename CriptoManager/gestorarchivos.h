#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include "cifrador.h"
class GestorArchivos
{
public:
    void cifrarArchivo(Cifrador* cifrador,string rutaEntrada,string rutaSalida);
    void descifrarArchivo(Cifrador* cifrador,string rutaEntrada,string rutaSalida);
};

#endif // GESTORARCHIVOS_H
