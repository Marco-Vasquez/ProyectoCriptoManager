#ifndef HISTORIALOPERACIONES_H
#define HISTORIALOPERACIONES_H
#include "operacion.h"
#include <string>
using namespace std;
class HistorialOperaciones
{
private:
    Operacion* listaOperaciones;
    int cantOperaciones;
    int capacidad;
    void redimensionar();
public:
    HistorialOperaciones();
    ~HistorialOperaciones();
    void registrarOperacion(string usuario,string tipoOperacion,string algoritmo,string archivo);
    void mostrarHistorial();
    void ordenarPorFecha();
    void buscarPorUsuario(string usuario);
    void generarReporte();
    void guardarEnArchivo(string ruta);
    void cargarDesdeArchivo(string ruta);
};

#endif // HISTORIALOPERACIONES_H
