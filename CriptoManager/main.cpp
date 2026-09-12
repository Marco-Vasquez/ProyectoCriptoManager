//Marco Vásquez 22541183 Laboratorio Progra III
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <string>
#include "cifrador.h"
#include "cifradorcesar.h"
#include "cifradorxor.h"
#include "cifradorvigenere.h"
#include "utilidades.h"
#include "gestorarchivos.h"
#include "gestorusuarios.h"
#include "historialoperaciones.h"
using namespace std;
int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Utilidades::colorTexto(14);
    cout<<"--- Proyecto: Cripto-Manager Cifrador y Descifrador de archivos ---"<<endl;
    Utilidades::colorTexto(7);
    GestorUsuarios gestorUsuarios;
    gestorUsuarios.cargarDesdeArchivo("usuarios.txt");
    HistorialOperaciones gestorHistorial;
    gestorHistorial.cargarDesdeArchivo("historial.txt");
    Usuario* usuarioActivo=NULL;
    while(usuarioActivo==NULL){
        Utilidades::colorTexto(14);
        cout<<"Bienvenido al sistema de ingreso"<<endl;
        Utilidades::colorTexto(7);
        cout<<"1. Iniciar sesión"<<endl;
        cout<<"2. Registrarme"<<endl;
        cout<<"3. Salir"<<endl;
        int opcionInicio=Utilidades::validarEntero("Opción: ",3);
        string nombreUsuario,contra;
        if(opcionInicio==3){
            return 0;
        }
        nombreUsuario=Utilidades::leerTextoNoVacio("Usuario: ");
        contra=Utilidades::leerTextoNoVacio("Contraseña: ");
        if(opcionInicio==1){
            usuarioActivo=gestorUsuarios.login(nombreUsuario,contra);
            if(usuarioActivo==NULL){
                Utilidades::colorTexto(12);
                cout<<"Usuario o contraseña incorrectos\n"<<endl;
                Utilidades::colorTexto(7);
            }
        }
        else{
            bool registrado=gestorUsuarios.registrarUsuario(nombreUsuario,contra,"usuario");
            if(registrado){
                Utilidades::colorTexto(10);
                cout<<"Usuario registrado con éxito. Inicie sesión\n"<<endl;
                Utilidades::colorTexto(7);
                gestorUsuarios.guardarEnArchivo("usuarios.txt");
            }
            else{
                Utilidades::colorTexto(12);
                cout<<"Ese nombre de usuario existe\n"<<endl;
                Utilidades::colorTexto(7);
            }
        }
    }
    Utilidades::pausarPantalla();
    int opcion;
    do{
        Utilidades::limpiarPantalla();
        Utilidades::colorTexto(10);
        cout<<"Sesion activa: "<<usuarioActivo->getNombre()<<"\n"<<endl;
        Utilidades::colorTexto(14);
        cout<<"--- MENU PRINCIPAL ---"<<endl;
        Utilidades::colorTexto(7);
        cout<<"1. Cifrado Cesar"<<endl;
        cout<<"2. Descifrado Cesar"<<endl;
        cout<<"3. Cifrado XOR"<<endl;
        cout<<"4. Descifrado XOR"<<endl;
        cout<<"5. Cifrado Vigenère"<<endl;
        cout<<"6. Descifrado Vigenère"<<endl;
        cout<<"7. Copiar archivo binario"<<endl;
        cout<<"8. Cifrar/Descifrar Archivo"<<endl;
        cout<<"9. Historial y reportes"<<endl;
        cout<<"10. Salir"<<endl;
        opcion=Utilidades::validarEntero("Ingrese una opcion: ",10);
        switch(opcion){
        case 1:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            int clave=Utilidades::validarEntero("Ingrese la clave (1-26): ",26);
            Cifrador* miCifrador=new CifradorCesar(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Cifrado","Cesar","consola");
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
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Descifrado","Cesar","consola");
            delete miCifrador;
            break;
        }
        case 3:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorXOR(clave);
            string cifrado=miCifrador->cifrar(mensaje);
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado (hex): "<<Utilidades::convertirHex(cifrado)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Cifrado","XOR","consola");
            delete miCifrador;
            break;
        }
        case 4:{
            string hexTexto=Utilidades::leerTextoNoVacio("Ingrese el mensaje cifrado (en hex, tal como se mostro): ");
            string clave=Utilidades::leerTextoNoVacio("Ingrese la clave: ");
            string textoBinario=Utilidades::hexATexto(hexTexto);
            Cifrador* miCifrador=new CifradorXOR(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(textoBinario)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Descifrado","XOR","consola");
            delete miCifrador;
            break;
        }
        case 5:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave (solo letras): ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje cifrado: "<<miCifrador->cifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Cifrado","Vigenere","consola");
            delete miCifrador;
            break;
        }
        case 6:{
            string mensaje=Utilidades::leerTextoNoVacio("Ingrese el mensaje: ");
            string clave=Utilidades::leerClaveAlfabetica("Ingrese la clave: ");
            Cifrador* miCifrador=new CifradorVigenere(clave);
            Utilidades::colorTexto(10);
            cout<<"Mensaje descifrado: "<<miCifrador->descifrar(mensaje)<<"\n"<<endl;
            Utilidades::colorTexto(7);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Descifrado","Vigenere","consola");
            delete miCifrador;
            break;
        }
        case 7:{
            string rutaEntrada=Utilidades::seleccionarArchivo();
            if(rutaEntrada.empty()){
                Utilidades::colorTexto(12);
                cout<<"No se selecciono ningun archivo\n"<<endl;
                Utilidades::colorTexto(7);
                break;
            }
            string rutaSalida=Utilidades::guardarArchivoComo();
            if(rutaSalida.empty()){
                Utilidades::colorTexto(12);
                cout<<"No se selecciono ruta de salida\n"<<endl;
                Utilidades::colorTexto(7);
                break;
            }
            Utilidades::copiarBinario(rutaEntrada,rutaSalida);
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),"Copia","Binario",rutaEntrada);
            break;
        }
        case 8:{
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
            Cifrador* miCifrador=NULL;
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
            string rutaEntrada=Utilidades::seleccionarArchivo();
            if(rutaEntrada.empty()){
                Utilidades::colorTexto(12);
                cout<<"No se selecciono ningun archivo\n"<<endl;
                delete miCifrador;
                Utilidades::colorTexto(7);
                break;
            }
            string rutaSalida=Utilidades::guardarArchivoComo();
            if(rutaSalida.empty()){
                Utilidades::colorTexto(12);
                cout<<"No se selecciono ruta de salida\n"<<endl;
                Utilidades::colorTexto(7);
                delete miCifrador;
                break;
            }
            GestorArchivos gestor;
            string tipoOp=(accion==1)?"Cifrado":"Descifrado";
            if(accion==1){
                gestor.cifrarArchivo(miCifrador,rutaEntrada,rutaSalida);
            }
            else{
                gestor.descifrarArchivo(miCifrador,rutaEntrada,rutaSalida);
            }
            gestorHistorial.registrarOperacion(usuarioActivo->getNombre(),tipoOp,miCifrador->getNombreAlgoritmo(),rutaEntrada);
            delete miCifrador;
            break;
        }
        case 9:{
            Utilidades::colorTexto(14);
            cout<<"\n--- HISTORIAL Y REPORTES ---"<<endl;
            Utilidades::colorTexto(7);
            cout<<"1. Ver historial completo"<<endl;
            cout<<"2. Ordenar historial por fecha"<<endl;
            cout<<"3. Buscar operaciones por usuario"<<endl;
            cout<<"4. Generar reporte de uso"<<endl;
            int opcionHistorial=Utilidades::validarEntero("Opcion: ",4);
            if(opcionHistorial==1){
                gestorHistorial.mostrarHistorial();
            }
            else if(opcionHistorial==2){
                gestorHistorial.ordenarPorFecha();
                Utilidades::colorTexto(10);
                cout<<"Historial ordenado por fecha\n"<<endl;
                Utilidades::colorTexto(7);
            }
            else if(opcionHistorial==3){
                string usuarioBuscado=Utilidades::leerTextoNoVacio("Ingrese el usuario a buscar: ");
                gestorHistorial.buscarPorUsuario(usuarioBuscado);
            }
            else{
                gestorHistorial.generarReporte();
            }
            break;
        }
        case 10:{
            gestorUsuarios.guardarEnArchivo("usuarios.txt");
            gestorHistorial.guardarEnArchivo("historial.txt");
            Utilidades::colorTexto(10);
            cout<<"Gracias por usar el cifrador de archivos!"<<endl;
            Utilidades::colorTexto(7);
            break;
        }
        default:{
            Utilidades::colorTexto(12);
            cout<<"Opcion inválida"<<endl;
            Utilidades::colorTexto(7);
            break;
        }
        }
        if(opcion!=10){
            Utilidades::pausarPantalla();
        }
    }while(opcion!=10);
    return 0;
}