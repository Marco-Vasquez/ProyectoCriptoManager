#include "gestorusuarios.h"
#include <iostream>
#include <fstream>
#include <sstream>
GestorUsuarios::GestorUsuarios()
{
    capacidad=5;
    cantUsuarios=0;
    listaUsuarios=new Usuario*[capacidad];
}
GestorUsuarios::~GestorUsuarios(){
    for(int i=0;i<cantUsuarios;i++){
        delete listaUsuarios[i];
    }
    delete[] listaUsuarios;
}
int GestorUsuarios::buscarUsuario(string nombre){
    for(int i=0;i<cantUsuarios;i++){
        if(listaUsuarios[i]->getNombre()==nombre){
            return i;
        }
    }
    return -1;
}
void GestorUsuarios::redimensionar(){
    int nuevaCapacidad=capacidad*2;
    Usuario** listaNueva=new Usuario*[nuevaCapacidad];
    for(int i=0;i<cantUsuarios;i++){
        listaNueva[i]=listaUsuarios[i]; //se copian las direcciones
    }
    delete[] listaUsuarios;
    listaUsuarios=listaNueva;
    capacidad=nuevaCapacidad;
}
bool GestorUsuarios::registrarUsuario(string nombre,string contra,string rol){
    if(buscarUsuario(nombre)!=-1){
        return false;
    }
    if(cantUsuarios==capacidad){
        redimensionar();
    }
    listaUsuarios[cantUsuarios]=new Usuario(nombre,contra,rol);
    cantUsuarios++;
    return true;
}
Usuario* GestorUsuarios::login(string nombre,string contra){
    int indice=buscarUsuario(nombre);
    if(indice==-1){
        return NULL;
    }
    if(listaUsuarios[indice]->getContra()==contra){
        return listaUsuarios[indice];
    }
    return NULL;
}
void GestorUsuarios::guardarEnArchivo(string ruta){
    ofstream salida(ruta);
    for(int i=0;i<cantUsuarios;i++){
        salida<<listaUsuarios[i]->getNombre()<<";"<<listaUsuarios[i]->getContra()<<";"
               <<listaUsuarios[i]->getRol()<<endl;
    }
    salida.close();
}
void GestorUsuarios::cargarDesdeArchivo(string ruta){
    ifstream entrada(ruta);
    if(!entrada){
        return;
    }
    string linea;
    while(getline(entrada,linea)){
        stringstream flujo(linea);
        string nombre,contra,rol;
        getline(flujo,nombre,';');
        getline(flujo,contra,';');
        getline(flujo,rol,';');
        if(!nombre.empty()){
            registrarUsuario(nombre,contra,rol);
        }
    }
    entrada.close();
}