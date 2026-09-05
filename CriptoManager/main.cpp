//Marco Vásquez 22541183 Laboratorio Progra III
#include <iostream>
#include <windows.h>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;
int validarEntero(string mensaje);
string cifrarCesar(string texto,int clave);
string descifrarCesar(string texto,int clave);
string cifrarXOR(string texto,string clave);
string descifrarXOR(string texto,string clave);
string cifrarVigenere(string texto,string clave);
string descifrarVigenere(string texto,string clave);
string convertirHex(string texto);
void copiarBinario(string rutaEntrada,string rutaSalida);
string limpiarRuta(string ruta);
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
        cout<<"6. Copiar archivo binario (probando)"<<endl;
        cout<<"7. Cifrar imagen (proximo)"<<endl;
        cout<<"8. Salir"<<endl;
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
            do{
                cout<<"Ingrese la clave: ";
                getline(cin,clave);
                if(clave.empty()){
                    cout<<"La clave no puede estar vacia\n";
                }
            }while(clave.empty());
            string cifrado=cifrarXOR(mensaje,clave);
            cout<<"Mensaje cifrado: "<<convertirHex(cifrado)<<"\n"<<endl;
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
            cout<<"Mensaje cifrado: "<<cifrado<<"\n"<<endl;
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
            cout<<"Mensaje descifrado: "<<descifrado<<"\n"<<endl;
            break;
        }
        case 6:{
            string rutaEntrada,rutaSalida;
            cout<<"Ingresa la ruta completa de la imagen: ";
            getline(cin,rutaEntrada);
            rutaEntrada=limpiarRuta(rutaEntrada);
            cout<<"Ingrese la ruta de salida (con nombre y extension, como: C:\\ruta\\copia.jpg): ";
            getline(cin,rutaSalida);
            rutaSalida=limpiarRuta(rutaSalida);
            copiarBinario(rutaEntrada,rutaSalida);
            break;
        }
        case 7:{
            cout<<"Proximamente"<<endl;
            break;
        }
        case 8:{
            cout<<"Saliendo...\n"<<endl;
            break;
        }
        default:{
            cout<<"Opción inválida"<<endl;
            break;
        }
        }
    }while(opcion!=8);
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
string convertirHex(string texto){
    stringstream flujo; //stringstream funciona como un cout sin mostrar en pantalla, guarda todo en el buffer
    for(int i=0;i<texto.length();i++){
        flujo<<hex<<setw(2)<<setfill('0')<<uppercase<<(int)(unsigned char)texto[i]<<" ";
        //hex funciona para convertir a hexadecimal
        //setfill rellena el espacio que deja el setw con 0 si el número no lo llena
        //uppercase transforma las letras a mayusculas (las de hexadecimal)
        //el unsigned char agarra el texto en esa posicion y lo convierte de 0-255 porque char normal puede ser negativo
        //el int se encarga de hacerlo entero porque stringstream agarra el dato tal cual en lugar del numero que representa
    }
    return flujo.str();
    //el str() es el encargado de que todo lo acumulado en flujo sea retornado como string normal
}
void copiarBinario(string rutaEntrada,string rutaSalida){
    ifstream entrada(rutaEntrada,ios::binary);
    if(!entrada){
        cout<<"No se pudo abrir el archivo de entrada"<<endl;
        return;
    }
    entrada.seekg(0,ios::end); //mueve el cursor de lectura al final del archivo
    long size=entrada.tellg(); //la funcion tellg() indica en que posición quedo (que es el tamaño de bytes)
    entrada.seekg(0,ios::beg); //esto regresa el cursos al inicio para leerlo desde ahi
    unsigned char* buffer=new unsigned char[size]; //reserva un bloque con el tamaño exacto del archivo
    entrada.read((char*)buffer,size); //lee todos los bytes de un solo hacia ese bloque reservado
    //el char* es necesario porque la funcion read() espera un char* aunque nuestro buffer (puntero) sea unsigned
    entrada.close();
    ofstream salida(rutaSalida,ios::binary);
    salida.write((char*)buffer,size);
    salida.close();
    delete[] buffer;
    cout<<"Archivo copiado: "<<size<<" bytes\n"<<endl;
}
string limpiarRuta(string ruta){
    //se valido con length que sea mayor o igual a dos como protección contra rutas vacias o de un solo caracter
    //evita que las funciones front() y back() choquen entre si
    //ruta.front() es el primer caracter del string y .back es el ultimo
    //si son comillas con sbstr empieza a extraer desde la posicion 1
    // y se le restan 2 por la comilla que se salta al inicio y la ultima comilla
    if(ruta.length()>=2 && ruta.front()=='"' && ruta.back()=='"'){
        ruta=ruta.substr(1,ruta.length()-2);
    }
    return ruta;
}