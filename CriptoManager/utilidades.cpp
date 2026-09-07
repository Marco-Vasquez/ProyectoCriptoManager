#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
int Utilidades::validarEntero(string mensaje,int maximo){
    int n;
    while(true){
        cout<<mensaje;
        cin>>n;
        if(cin.fail() || n<=0 || n>maximo){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Entrada invalida, ingrese un numero entre 1 y "<<maximo<<endl;
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
            cout<<"El texto no puede estar vacio"<<endl;
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
        cout<<"No se puedo abrir el archivo de entrada"<<endl;
        return;
    }
    entrada.seekg(0,ios::end);
    long size=entrada.tellg();
    entrada.seekg(0,ios::beg);
    unsigned char*buffer=new unsigned char[size];
    entrada.read((char*)buffer,size);
    entrada.close();
    ofstream salida(rutaSalida,ios::binary);
    salida.write((char*)buffer,size);
    salida.close();
    delete[] buffer;
    cout<<"Archivo copiado: "<<size<<" bytes"<<endl;
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
            cout<<"La clave debe tener solo letras, sin espacios ni simbolos\n"<<endl;
        }
    }while(!valida);
    return clave;
}