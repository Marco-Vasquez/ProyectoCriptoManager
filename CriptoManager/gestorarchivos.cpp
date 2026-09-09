#include "gestorarchivos.h"
#include "utilidades.h"
#include <iostream>
#include <fstream>
void GestorArchivos::cifrarArchivo(Cifrador* cifrador,string rutaEntrada,string rutaSalida){
    ifstream entrada(rutaEntrada,ios::binary);
    if(!entrada){
        Utilidades::colorTexto(12);
        cout<<"No se pudo abrir el archivo de entrada\n"<<endl;
        Utilidades::colorTexto(7);
        return;
    }
    entrada.seekg(0,ios::end);
    long size=entrada.tellg();
    entrada.seekg(0,ios::beg);
    unsigned char* buffer=new unsigned char[size];
    entrada.read((char*)buffer,size);
    entrada.close();
    unsigned char* resultado=new unsigned char[size];
    for(long i=0;i<size;i++){
        resultado[i]=(unsigned char)cifrador->cifrarByte(buffer[i],i);
    }
    ofstream salida(rutaSalida,ios::binary);
    if(!salida){
        Utilidades::colorTexto(12);
        cout<<"No se pudo crear el archivo, verifique la ruta"<<endl;
        delete[] buffer;
        delete[] resultado;
        return;
    }
    salida.write((char*)resultado,size);
    salida.close();
    delete[] buffer;
    delete[] resultado;
    Utilidades::colorTexto(10);
    cout<<"Archivo cifrado: "<<size<<" bytes"<<endl;
    Utilidades::colorTexto(7);
}
void GestorArchivos::descifrarArchivo(Cifrador* cifrador,string rutaEntrada,string rutaSalida){
    ifstream entrada(rutaEntrada,ios::binary);
    if(!entrada){
        Utilidades::colorTexto(12);
        cout<<"No se pudo abrir el archivo de entrada"<<endl;
        Utilidades::colorTexto(7);
        return;
    }
    entrada.seekg(0,ios::end);
    long size=entrada.tellg();
    entrada.seekg(0,ios::beg);
    unsigned char* buffer=new unsigned char[size];
    entrada.read((char*)buffer,size);
    entrada.close();
    unsigned char* resultado=new unsigned char[size];
    for(long i=0;i<size;i++){
        resultado[i]=(unsigned char)cifrador->descifrarByte(buffer[i],i);
    }
    ofstream salida(rutaSalida,ios::binary);
    if(!salida){
        Utilidades::colorTexto(12);
        cout<<"No se pudo crear el archivo, verifique la ruta"<<endl;
        delete[] buffer;
        delete[] resultado;
        return;
    }
    salida.write((char*)resultado,size);
    salida.close();
    delete[] buffer;
    delete[] resultado;
    Utilidades::colorTexto(10);
    cout<<"Archivo descifrado: "<<size<<" bytes\n"<<endl;
    Utilidades::colorTexto(7);
}
