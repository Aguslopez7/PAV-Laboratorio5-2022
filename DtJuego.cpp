#include "DtJuego.h"

DtJuego::DtJuego(){}

DtJuego::DtJuego(string nombre, DtCategoria* categoria, string empresa, int totalHorasJuego, float puntajePromedio, string descripcion, int costo)
{
    this->nombre=nombre;
    this->categoria=categoria;
    this->empresa=empresa;
    this->totalHorasJuego=totalHorasJuego;
    this->puntajePromedio=puntajePromedio;
    this->descripcion=descripcion;
    this->costo=costo;
}

void DtJuego::setNombre(string nombre){
    this->nombre=nombre;
}

void DtJuego::setCategoria(DtCategoria* categoria){
    this->categoria=categoria;
}

void DtJuego::setEmpresa(string empresa){
     this->empresa=empresa;
    
}

void DtJuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

void DtJuego::setPuntajePromedio (float puntajePromedio){
    this->puntajePromedio=puntajePromedio;

}

void DtJuego::setTotalHorasJuego(int totalHorasJuego){
    this->totalHorasJuego=totalHorasJuego;

}

void DtJuego::setCosto(int costo){
    this->costo=costo;
}

string DtJuego::getNombre(){
    return this->nombre;
}

DtCategoria* DtJuego::getCategoria(){
    return this->categoria;
}

string DtJuego::getEmpresa(){
    return this->empresa;
}

string DtJuego::getDescripcion(){
    return this->descripcion;
}

float DtJuego::getPuntajePromedio(){
    return this->puntajePromedio;
}

int DtJuego::getTotalHorasJuego(){
    return this->totalHorasJuego;
}

int DtJuego:: getCosto(){
    return this->costo;
}

DtJuego::~DtJuego(){}
