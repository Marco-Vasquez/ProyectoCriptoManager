//Marco Vásquez 22541183 Laboratorio Progra III
#include <iostream>
#include <windows.h>
#include <string>
#include "cifrador.h"
#include "cifradorcesar.h"
#include "cifradorxor.h"
#include "cifradorvigenere.h"
#include "utilidades.h"
using namespace std;
int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int opcion;
    cout<<"--- Proyecto: Cripto-Manager Cifrador y Descifrador de archivos ---"<<endl;
    do{
        cout<<"--- MENU PRINCIPAL ---"<<endl;
        cout<<"1. Cifrado Cesar"<<endl;
        cout<<"2. Descifrado Cesar"<<endl;
        cout<<"3. Cifrado XOR (prototipo descifrado)"<<endl;
        cout<<"4. Cifrado Vigenere"<<endl;
        cout<<"5. Descifrado Vigenere"<<endl;
        cout<<"6. Copiar archivo binario (prueba)"<<endl;
        cout<<"7. Cifrar imagen (proximamente)"<<endl;
        cout<<"8. Salir"<<endl;
        opcion=Utilidades::validarEntero("Ingrese una opcion: ",8);
        switch(opcion){
        case 1:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            int clave=Utilidades::validarEntero("Ingrese la clave (1-26): ",26);
            Cifrador* miCifrador=new CifradorCesar(clave);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            delete miCifrador;
            break;
        }
        case 2:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            int clave=Utilidades::validarEntero("Ingrese la clave (1-26): ",26);
            Cifrador* miCifrador=new CifradorCesar(clave);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(mensaje)<<"\n"<<endl;
            delete miCifrador;
            break;
        }
        case 3:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorXOR(clave);
            string cifrado=miCifrador->cifrar(mensaje);
            cout<<"Mensaje cifrado: "<<Utilidades::convertirHex(cifrado)<<"\n"<<endl;
            cout<<"Probando descifrador: "<<miCifrador->descifrar(cifrado)<<"\n"<<endl;
            delete miCifrador;
            break;
        }
        case 4:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave (solo letras): ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            delete miCifrador;
            break;
        }
        case 5:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(mensaje)<<"\n"<<endl;
            delete miCifrador;
            break;
        }
        case 6:{
            string rutaEntrada=Utilidades::leerTextoNoVacio("Ingrese la ruta de la imagen (o arrastrela a esta ventana): ");
            rutaEntrada=Utilidades::limpiarRuta(rutaEntrada);
            string rutaSalida=Utilidades::leerTextoNoVacio("Ingrese la ruta de salida (donde quiere la imagen): ");
            rutaSalida=Utilidades::limpiarRuta(rutaSalida);
            Utilidades::copiarBinario(rutaEntrada,rutaSalida);
            break;
        }
        case 7:{
            cout<<"Proximamente..."<<endl;
            break;
        }
        default:{
            cout<<"Opcion inválida"<<endl;
            break;
        }
        }
    }while(opcion!=8);
}