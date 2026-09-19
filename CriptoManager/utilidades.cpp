#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <commdlg.h>
#endif
#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cctype>
#ifndef _WIN32
#include <filesystem>
#ifdef __linux__
#include <unistd.h>
#endif
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif
#endif
int Utilidades::validarEntero(string mensaje,int maximo){
    int n;
    while(true){
        cout<<mensaje;
        cin>>n;
        if(cin.fail() || n<=0 || n>maximo){
            cin.clear();
            cin.ignore(1000,'\n');
            Utilidades::colorTexto(12);
            cout<<"Entrada invalida, ingrese un numero entre 1 y "<<maximo<<endl;
            Utilidades::colorTexto(7);
        }
        else{
            cin.ignore(1000,'\n');
            return n;
        }
    }
}
string Utilidades::leerTextoNoVacio(string mensaje){
    string texto;
    do{
        cout<<mensaje;
        getline(cin,texto);
        if(texto.empty()){
            Utilidades::colorTexto(12);
            cout<<"El texto no puede estar vacio\n"<<endl;
            Utilidades::colorTexto(7);
        }
    }while(texto.empty());
    return texto;
}
string Utilidades::limpiarRuta(string ruta){
    if(ruta.length()>=2 && ruta.front()=='"' && ruta.back()=='"'){
        ruta=ruta.substr(1,ruta.length()-2);
    }
    return ruta;
}
string Utilidades::convertirHex(string texto){
    stringstream flujo;
    for(int i=0;i<texto.length();i++){
        flujo<<hex<<setw(2)<<setfill('0')<<uppercase<<(int)(unsigned char)texto[i]<<" ";
    }
    return flujo.str();
}
void Utilidades::copiarBinario(string rutaEntrada,string rutaSalida){
    ifstream entrada(rutaEntrada,ios::binary);
    if(!entrada){
        Utilidades::colorTexto(12);
        cout<<"No se puedo abrir el archivo de entrada\n"<<endl;
        Utilidades::colorTexto(7);
        return;
    }
    entrada.seekg(0,ios::end);
    long size=entrada.tellg();
    entrada.seekg(0,ios::beg);
    unsigned char*buffer=new unsigned char[size];
    entrada.read((char*)buffer,size);
    entrada.close();
    ofstream salida(rutaSalida,ios::binary);
    if(!salida){
        Utilidades::colorTexto(12);
        cout<<"No se pudo crear el archivo, verifique la ruta"<<endl;
        delete[] buffer;
        return;
    }
    salida.write((char*)buffer,size);
    salida.close();
    delete[] buffer;
    Utilidades::colorTexto(10);
    cout<<"Archivo copiado: "<<size<<" bytes\n"<<endl;
    Utilidades::colorTexto(7);
}
string Utilidades::leerClaveAlfabetica(string mensaje){
    string clave;
    bool valida;
    do{
        cout<<mensaje;
        getline(cin,clave);
        valida=!clave.empty();
        for(int i=0;i<clave.length();i++){
            if(!isalpha(clave[i])){
                valida=false;
            }
        }
        if(!valida){
            Utilidades::colorTexto(12);
            cout<<"La clave debe tener solo letras, sin espacios ni simbolos\n"<<endl;
            Utilidades::colorTexto(7);
        }
    }while(!valida);
    return clave;
}
void Utilidades::colorTexto(int color){
#ifdef _WIN32
    HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola,color);
#else
    switch(color){
    case 10:
        cout<<"\033[32m";
        break;
    case 12:
        cout<<"\033[31m";
        break;
    case 14:
        cout<<"\033[33m";
        break;
    case 11:
        cout<<"\033[36m";
        break;
    default:
        cout<<"\033[0m";
        break;
    }
#endif
}
void Utilidades::limpiarPantalla(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void Utilidades::pausarPantalla(){
    cout<<"Presione ENTER para continuar..."<<endl;
    if(cin.rdbuf()->in_avail()>0){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.get();
}
string Utilidades::seleccionarArchivo(){
#ifdef _WIN32
    char rutaSeleccionada[260]="";
    OPENFILENAMEA ventana;
    ZeroMemory(&ventana,sizeof(ventana));
    ventana.lStructSize=sizeof(ventana);
    ventana.hwndOwner=NULL;
    ventana.lpstrFile=rutaSeleccionada;
    ventana.nMaxFile=260;
    ventana.lpstrFilter="Todos los archivos\0*.*\0";
    ventana.nFilterIndex=1;
    ventana.Flags=OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if(GetOpenFileNameA(&ventana)){
        return string(rutaSeleccionada);
    }
    return "";
#else
    string ruta;
    cout<<"Ingrese la ruta del archivo: ";
    getline(cin,ruta);
    return ruta;
#endif
}
string Utilidades::guardarArchivoComo(){
#ifdef _WIN32
    char rutaSeleccionada[260]="";
    OPENFILENAMEA ventana;
    ZeroMemory(&ventana,sizeof(ventana));
    ventana.lStructSize=sizeof(ventana);
    ventana.hwndOwner=NULL;
    ventana.lpstrFile=rutaSeleccionada;
    ventana.nMaxFile=260;
    ventana.lpstrFilter="Todos los archivos\0*.*\0";
    ventana.nFilterIndex=1;
    ventana.Flags=OFN_OVERWRITEPROMPT;
    if(GetSaveFileNameA(&ventana)){
        return string(rutaSeleccionada);
    }
    return "";
#else
    string ruta;
    cout<<"Ingrese la ruta del archivo: ";
    getline(cin,ruta);
    return ruta;
#endif
}
string Utilidades::obtenerFechaHora(){
    time_t ahora=time(0);
    tm* horaLocal=localtime(&ahora);
    char buffer[20];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d %H:%M:%S",horaLocal);
    return string(buffer);
}
string Utilidades::hexATexto(string hexTexto){
    string resultado="";
    stringstream flujo(hexTexto);
    string par;
    while(flujo>>par){
        int valor=stoi(par,nullptr,16);
        resultado+=(char)valor;
    }
    return resultado;
}
bool Utilidades::esArchivoTexto(string ruta){
    if(ruta.length()<4){
        return false;
    }
    string extension=ruta.substr(ruta.length()-4);
    for(int i=0;i<extension.length();i++){
        extension[i]=tolower(extension[i]);
    }
    return extension==".txt";
}
string Utilidades::leerContenidoArchivo(string ruta){
    ifstream entrada(ruta,ios::binary);
    if(!entrada){
        return "";
    }
    stringstream flujo;
    flujo<<entrada.rdbuf();
    entrada.close();
    return flujo.str();
}
string Utilidades::rutaBase(){
#ifdef _WIN32
    char ruta[MAX_PATH];
    GetModuleFileNameA(NULL,ruta,MAX_PATH);
    string rutaCompleta(ruta);
    int pos=rutaCompleta.find_last_of("\\/");
    return rutaCompleta.substr(0,pos+1);
#elif defined(__linux__)
    char ruta[4096];
    ssize_t tamano=readlink("/proc/self/exe",ruta,sizeof(ruta)-1);
    if(tamano!=-1){
        ruta[tamano]='\0';
        string rutaCompleta(ruta);
        int pos=rutaCompleta.find_last_of("/");
        return rutaCompleta.substr(0,pos+1);
    }
    return filesystem::current_path().string()+"/";
#elif defined(__APPLE__)
    uint32_t tamano=0;
    _NSGetExecutablePath(NULL,&tamano);
    char*ruta=new char[tamano];
    if(_NSGetExecutablePath(ruta,&tamano)==0){
        string rutaCompleta(ruta);
        delete[] ruta;
        int pos=rutaCompleta.find_last_of("/");
        return rutaCompleta.substr(0,pos+1);
    }
    delete[] ruta;
    return filesystem::current_path().string()+"/";
#else
    return filesystem::current_path().string()+"/";
#endif
}
string Utilidades::hashContra(string contra){
    unsigned long hash=5381; //algoritmo djb2
    for(int i=0;i<contra.length();i++){
        //empieza con el numero base y por cada caracter
        //lo combina con hash*33+caracter (o mas sencillo (hash<<5)+hash
        //se usa para multiplicar por 33 usando desplazamiento de bits
        hash=((hash<<5)+hash)+(unsigned char)contra[i];
    }
    stringstream flujo;
    flujo<<hex<<hash;
    return flujo.str();
}