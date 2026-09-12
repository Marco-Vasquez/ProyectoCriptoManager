#ifndef GESTORUSUARIOS_H
#define GESTORUSUARIOS_H
#include "usuario.h"
#include <string>
using namespace std;
class GestorUsuarios
{
private:
    Usuario** listaUsuarios;
    int cantUsuarios;
    int capacidad;
    void redimensionar();
    int buscarUsuario(string nombreUsuario);
public:
    GestorUsuarios();
    ~GestorUsuarios();
    bool registrarUsuario(string nombre,string contra,string rol);
    Usuario* login(string nombre,string contra);
    void guardarEnArchivo(string ruta);
    void cargarDesdeArchivo(string ruta);
};

#endif // GESTORUSUARIOS_H
