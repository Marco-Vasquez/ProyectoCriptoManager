//Marco Vásquez 22541183 Laboratorio Progra III
#include <iostream>
#include <windows.h>
#include <string>
#include <cctype>
using namespace std;
int validarEntero(string mensaje);
string cifrarCesar(string texto,int clave);
string descifrarCesar(string texto,int clave);
string cifrarXOR(string texto,string clave);
string descifrarXOR(string texto,string clave);
string cifrarVigenere(string texto,string clave);
string descifrarVigenere(string texto,string clave);

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    int opcion;
    cout<<"--- Proyecto: Cifrado y descifrado de archivos ---"<<endl;
    do{
        cout<<"--- MENÚ PRINCIPAL ---"<<endl;
        cout<<"1. Cifrado César"<<endl;
        cout<<"2. Descifrado César"<<endl;
        cout<<"3. Cifrado XOR (protopito descifrado)"<<endl;
        cout<<"4. Cifrado Vigénere"<<endl;
        cout<<"5. Descifrar Vigénere"<<endl;
        cout<<"6. Salir"<<endl;
        opcion=validarEntero("Ingrese una opción: ");
        switch(opcion){
        case 1:{
            string mensaje;
            cout<<"Ingrese el mensaje: ";
            getline(cin,mensaje);
            int clave=validarEntero("Ingrese la clave: ");
            mensaje=cifrarCesar(mensaje,clave);
            cout<<"Mensaje cifrado: "<<mensaje<<"\n"<<endl;
            break;
        }
        case 2:{
            string mensaje;
            cout<<"Ingrese el mensaje cifrado: ";
            getline(cin,mensaje);
            int clave=validarEntero("Ingrese la clave (1-26): ");
            mensaje=descifrarCesar(mensaje,clave);
            cout<<"Mensaje descifrado: "<<mensaje<<"\n"<<endl;
            break;
        }
        case 3:{
            string mensaje;
            cout<<"Ingrese el mensaje: ";
            getline(cin,mensaje);
            string clave;
            cout<<"Ingrese la clave: ";
            getline(cin,clave);
            string cifrado=cifrarXOR(mensaje,clave);
            cout<<"Mensaje cifrado: "<<cifrado<<"\n"<<endl;
            string descifrado=descifrarXOR(cifrado,clave);
            cout<<"Probando descifrador: "<<descifrado<<"\n"<<endl;
            break;
        }
        case 4:{
            string mensaje;
            cout<<"Ingrese el mensaje: ";
            getline(cin,mensaje);
            string clave;
            cout<<"Ingrese la clave: ";
            getline(cin,clave);
            string cifrado=cifrarVigenere(mensaje,clave);
            cout<<"Mensaje cifrado: "<<cifrado<<endl;
            break;
        }
        case 5:{
            string mensaje;
            cout<<"Ingrese el mensaje: ";
            getline(cin,mensaje);
            string clave;
            cout<<"Ingrese la clave: ";
            getline(cin,clave);
            string descifrado=descifrarVigenere(mensaje,clave);
            cout<<"Mensaje descifrado: "<<descifrado<<endl;
            break;
        }
        case 6:{
            cout<<"Saliendo...\n"<<endl;
            break;
        }
        default:{
            cout<<"Opción inválida"<<endl;
            break;
        }
        }
    }while(opcion!=6);
    return 0;
}
int validarEntero(string mensaje){
    int n;
    while(true){
        cout<<mensaje;
        cin>>n;
        if(cin.fail() || n<=0 || n>26){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Entrada invalida, ingrese un numero entero positivo válido\n";
        }else{
            cin.ignore(1000,'\n');
            return n;
        }
    }
}
string cifrarCesar(string texto,int clave){
    string resultado="";
    clave=clave%26;
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        if(isupper(letra)){
            resultado+=char((letra-'A'+clave)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'+clave)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
string descifrarCesar(string texto,int clave){
    string resultado="";
    clave=clave%26;
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        if(isupper(letra)){
            resultado+=char((letra-'A'-clave+26)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'-clave+26)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
string cifrarXOR(string texto,string clave){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char caracterClave=clave[i%longitudClave];
        resultado+=char(texto[i]^caracterClave);
    }
    return resultado;
}
string descifrarXOR(string texto,string clave){
    return cifrarXOR(texto,clave);
}
string cifrarVigenere(string texto,string clave){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        char caracterClave=clave[i%longitudClave];
        int valorClave=toupper(caracterClave)-'A';
        if(isupper(letra)){
            resultado+=char((letra-'A'+valorClave)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'+valorClave)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}
string descifrarVigenere(string texto,string clave){
    string resultado="";
    int longitudClave=clave.length();
    for(int i=0;i<texto.length();i++){
        char letra=texto[i];
        char caracterClave=clave[i%longitudClave];
        int valorClave=toupper(caracterClave)-'A';
        if(isupper(letra)){
            resultado+=char((letra-'A'-valorClave+26)%26+'A');
        }
        else if(islower(letra)){
            resultado+=char((letra-'a'-valorClave+26)%26+'a');
        }
        else{
            resultado+=letra;
        }
    }
    return resultado;
}