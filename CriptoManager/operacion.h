#ifndef OPERACION_H
#define OPERACION_H
#include <string>
using namespace std;
class Operacion
{
private:
    string usuario;
    string tipoOperacion;
    string algoritmo;
    string archivo;
    string fechaHora;
public:
    Operacion();
    Operacion(string _usuario,string _tipoOperacion,string _algoritmo,string _archivo,string _fechaHora);
    ~Operacion();
    string getUsuario();
    string getTipoOperacion();
    string getAlgoritmo();
    string getArchivo();
    string getFechaHora();
};

#endif // OPERACION_H
