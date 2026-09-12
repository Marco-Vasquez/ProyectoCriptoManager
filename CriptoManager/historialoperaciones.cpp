#include "historialoperaciones.h"
#include "utilidades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
HistorialOperaciones::HistorialOperaciones() {
    capacidad=5;
    cantOperaciones=0;
    listaOperaciones=new Operacion[capacidad];
}
HistorialOperaciones::~HistorialOperaciones(){
    delete[] listaOperaciones;
}
void HistorialOperaciones::redimensionar(){
    int nuevaCapacidad=capacidad*2;
    Operacion* listaNueva=new Operacion[nuevaCapacidad];
    for(int i=0;i<cantOperaciones;i++){
        listaNueva[i]=listaOperaciones[i];
    }
    delete[] listaOperaciones;
    listaOperaciones=listaNueva;
    capacidad=nuevaCapacidad;
}
void HistorialOperaciones::registrarOperacion(string usuario,string tipoOperacion,string algoritmo,string archivo){
    if(cantOperaciones==capacidad){
        redimensionar();
    }
    string fechaHora=Utilidades::obtenerFechaHora();
    listaOperaciones[cantOperaciones]=Operacion(usuario,tipoOperacion,algoritmo,archivo,fechaHora);
    cantOperaciones++;
}
void HistorialOperaciones::mostrarHistorial(){
    if(cantOperaciones==0){
        Utilidades::colorTexto(12);
        cout<<"No hay operaciones registradas todavia\n"<<endl;
        Utilidades::colorTexto(7);
        return;
    }
    cout<<left<<setw(20)<<"\nFecha y hora"<<setw(10)<<"Usuario"<<setw(12)<<"Tipo"<<setw(12)<<"Algoritmo"<<"Archivo"<<endl;
    cout<<string(70,'-')<<endl;
    for(int i=0;i<cantOperaciones;i++){
        cout<<left<<setw(20)<<listaOperaciones[i].getFechaHora()<<setw(10)<<listaOperaciones[i].getUsuario()<<setw(12)<<listaOperaciones[i].getTipoOperacion()<<setw(12)<<listaOperaciones[i].getAlgoritmo()<<listaOperaciones[i].getArchivo()<<endl;
    }
}
void HistorialOperaciones::ordenarPorFecha(){
    for(int i=0;i<cantOperaciones-1;i++){
        for(int j=0;j<cantOperaciones-1-i;j++){
            if(listaOperaciones[j].getFechaHora()>listaOperaciones[j+1].getFechaHora()){
                Operacion temp=listaOperaciones[j];
                listaOperaciones[j]=listaOperaciones[j+1];
                listaOperaciones[j+1]=temp;
            }
        }
    }
}
void HistorialOperaciones::buscarPorUsuario(string usuario){
    bool encontrado=false;
    cout<<left<<setw(20)<<"Fecha y hora"<<setw(12)<<"Tipo"<<setw(12)<<"Algoritmo"<<"Archivo"<<endl;
    cout<<string(70,'-')<<endl;
    for(int i=0;i<cantOperaciones;i++){
        if(listaOperaciones[i].getUsuario()==usuario){
            cout<<left<<setw(20)<<listaOperaciones[i].getFechaHora()<<setw(12)<<listaOperaciones[i].getTipoOperacion()<<setw(12)<<listaOperaciones[i].getAlgoritmo()<<listaOperaciones[i].getArchivo()<<endl;
            encontrado=true;
        }
    }
    if(!encontrado){
        Utilidades::colorTexto(12);
        cout<<"No se encontraron operaciones para ese usuario\n"<<endl;
        Utilidades::colorTexto(7);
    }
}
void HistorialOperaciones::generarReporte(){
    int totalCesar=0,totalXOR=0,totalVigenere=0;
    for(int i=0;i<cantOperaciones;i++){
        if(listaOperaciones[i].getAlgoritmo()=="Cesar"){
            totalCesar++;
        }
        else if(listaOperaciones[i].getAlgoritmo()=="XOR"){
            totalXOR++;
        }
        else if(listaOperaciones[i].getAlgoritmo()=="Vigenere"){
            totalVigenere++;
        }
    }
    Utilidades::colorTexto(14);
    cout<<"\n--- REPORTE DE OPERACIONES ---"<<endl;
    Utilidades::colorTexto(10);
    cout<<"Cesar: "<<totalCesar<<endl;
    cout<<"XOR: "<<totalXOR<<endl;
    cout<<"Vigenere: "<<totalVigenere<<"\n"<<endl;
    Utilidades::colorTexto(7);
}
void HistorialOperaciones::guardarEnArchivo(string ruta){
    ofstream salida(ruta);
    for(int i=0;i<cantOperaciones;i++){
        salida<<listaOperaciones[i].getUsuario()<<";"<<listaOperaciones[i].getTipoOperacion()<<";"<<listaOperaciones[i].getAlgoritmo()<<";"<<listaOperaciones[i].getArchivo()<<";"<<listaOperaciones[i].getFechaHora()<<endl;
    }
    salida.close();
}
void HistorialOperaciones::cargarDesdeArchivo(string ruta){
    ifstream entrada(ruta);
    if(!entrada){
        return;
    }
    string linea;
    while(getline(entrada,linea)){
        stringstream flujo(linea);
        string usuario,tipoOperacion,algoritmo,archivo,fechaHora;
        getline(flujo,usuario,';');
        getline(flujo,tipoOperacion,';');
        getline(flujo,algoritmo,';');
        getline(flujo,archivo,';');
        getline(flujo,fechaHora,';');
        if(!usuario.empty()){
            if(cantOperaciones==capacidad){
                redimensionar();
            }
            listaOperaciones[cantOperaciones]=Operacion(usuario,tipoOperacion,algoritmo,archivo,fechaHora);
            cantOperaciones++;
        }
    }
    entrada.close();
}
