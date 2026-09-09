#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <string>
using namespace std;
class Utilidades
{
public:
    static int validarEntero(string mensaje,int maximo);
    static string leerTextoNoVacio(string mensaje);
    static string limpiarRuta(string ruta);
    static string convertirHex(string texto);
    static void copiarBinario(string rutaEntrada,string rutaSalida);
    static string leerClaveAlfabetica(string mensaje);
    static void colorTexto(int color);
};

#endif // UTILIDADES_H
