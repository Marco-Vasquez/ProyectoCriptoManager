#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;
class Usuario
{
private:
    string nombre;
    string contra;
    string rol;
public:
    Usuario(string _nombre,string _contra,string _rol);
    ~Usuario();
    string getNombre();
    string getContra();
    string getRol();
};

#endif // USUARIO_H
