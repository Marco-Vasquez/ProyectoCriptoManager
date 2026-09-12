#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <commdlg.h>
#include <ctime>
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
    HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consola,color);
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
    if(cin.rdbuf()->in_avail()>0){ //evalua si el buffer tiene algo por limpiar, si lo tiene lo limpia
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.get();
}
string Utilidades::seleccionarArchivo(){
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
}
string Utilidades::guardarArchivoComo(){
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