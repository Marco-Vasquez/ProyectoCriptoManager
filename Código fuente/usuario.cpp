#include "usuario.h"

Usuario::Usuario(string _nombre,string _contra,string _rol) {
    nombre=_nombre;
    contra=_contra;
    rol=_rol;
}
Usuario::~Usuario(){}
string Usuario::getNombre(){
    return nombre;
}
string Usuario::getContra(){
    return contra;
}
string Usuario::getRol(){
    return rol;
}
