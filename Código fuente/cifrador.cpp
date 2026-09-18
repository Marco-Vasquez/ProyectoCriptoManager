#include "cifrador.h"

Cifrador::Cifrador(string nombre) {
    nombreAlgoritmo=nombre;
}
Cifrador::~Cifrador(){}
string Cifrador::getNombreAlgoritmo(){
    return nombreAlgoritmo;
}