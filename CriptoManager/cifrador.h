#ifndef CIFRADOR_H
#define CIFRADOR_H
#include <string>
using namespace std;
class Cifrador {
protected:
    string nombreAlgoritmo;
public:
    Cifrador(string nombre);
    virtual ~Cifrador();
    virtual string cifrar(string texto)=0;
    virtual string descifrar(string texto)=0;
    string getNombreAlgoritmo();
    virtual char cifrarByte(unsigned char byte,int posicion)=0;
    virtual char descifrarByte(unsigned char byte,int posicion)=0;
};
#endif