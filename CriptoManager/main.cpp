//Marco Vásquez 22541183 Laboratorio Progra III
#include <iostream>
#include <windows.h>
#include <string>
#include "cifrador.h"
#include "cifradorcesar.h"
#include "cifradorxor.h"
#include "cifradorvigenere.h"
#include "utilidades.h"
#include "gestorarchivos.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
using namespace std;
int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int opcion;
    Utilidades::colorTexto(14);
    cout<<"--- Proyecto: Cripto-Manager Cifrador y Descifrador de archivos ---"<<endl;
    Utilidades::colorTexto(7);
    do{
        Utilidades::colorTexto(14);
        cout<<"--- MENU PRINCIPAL ---"<<endl;
        Utilidades::colorTexto(7);
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
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            delete miCifrador;
            break;
        }
        case 2:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            int clave=Utilidades::validarEntero("Ingrese la clave (1-26): ",26);
            Cifrador* miCifrador=new CifradorCesar(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            delete miCifrador;
            break;
        }
        case 3:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorXOR(clave);
            string cifrado=miCifrador->cifrar(mensaje);
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado: "<<Utilidades::convertirHex(cifrado)<<"\n"<<endl;
            cout<<"Probando descifrador: "<<miCifrador->descifrar(cifrado)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            delete miCifrador;
            break;
        }
        case 4:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave (solo letras): ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            delete miCifrador;
            break;
        }
        case 5:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
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
            Utilidades::colorTexto(14);
            cout<<"Elija el algoritmo que desea usar: "<<endl;
            Utilidades::colorTexto(7);
            cout<<"1. Cesar"<<endl;
            cout<<"2. XOR"<<endl;
            cout<<"3. Vigenere"<<endl;
            int algoritmo=Utilidades::validarEntero("Opcion: ",3);
            Utilidades::colorTexto(14);
            cout<<"Elija la acción que desea realizar: "<<endl;
            Utilidades::colorTexto(7);
            cout<<"1. Cifrar"<<endl;
            cout<<"2. Descifrar"<<endl;
            int accion=Utilidades::validarEntero("Opcion: ",2);
            Cifrador* miCifrador=NULL; //puntero génerico que no sabe a que hijo apuntara
            if(algoritmo==1){
                int clave=Utilidades::validarEntero("Ingrese la clave (1-255): ",255);
                miCifrador=new CifradorCesar(clave);
            }
            else if(algoritmo==2){
                string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
                miCifrador=new CifradorXOR(clave);
            }
            else{
                string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
                miCifrador=new CifradorVigenere(clave);
            }
            string rutaEntrada=Utilidades::leerTextoNoVacio("Ingrese la ruta del archivo (o arrastrelo a esta ventana): ");
            rutaEntrada=Utilidades::limpiarRuta(rutaEntrada);
            string rutaSalida=Utilidades::leerTextoNoVacio("Ingrese la ruta de salida (es similar a la de entrada): ");
            rutaSalida=Utilidades::limpiarRuta(rutaSalida);
            GestorArchivos gestor;
            if(accion==1){
                gestor.cifrarArchivo(miCifrador,rutaEntrada,rutaSalida);
            }
            else{
                gestor.descifrarArchivo(miCifrador,rutaEntrada,rutaSalida);
            }
            delete miCifrador;
            break;
        }
        case 8:{
            Utilidades::colorTexto(10);
            cout<<"Gracias por usar el cifrador de archivos!"<<endl;
            Utilidades::colorTexto(7);
            break;
        }
        default:{
            cout<<"Opcion inválida"<<endl;
            break;
        }
        }
    }while(opcion!=8);
    return 0;
}