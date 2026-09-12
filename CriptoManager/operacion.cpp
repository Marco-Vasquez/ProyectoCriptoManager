#include "operacion.h"

Operacion::Operacion() {}
Operacion::Operacion(string _usuario,string _tipoOperacion,string _algoritmo,string _archivo,string _fechaHora){
    usuario=_usuario;
    tipoOperacion=_tipoOperacion;
    algoritmo=_algoritmo;
    archivo=_archivo;
    fechaHora=_fechaHora;
}
Operacion::~Operacion(){}
string Operacion::getUsuario(){
    return usuario;
}
string Operacion::getTipoOperacion(){
    return tipoOperacion;
}
string Operacion::getAlgoritmo(){
    return algoritmo;
}
string Operacion::getArchivo(){
    return archivo;
}
string Operacion::getFechaHora(){
    return fechaHora;
}
