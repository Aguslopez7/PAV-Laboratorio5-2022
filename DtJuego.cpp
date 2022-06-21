#include "DtJuego.h"

DtJuego::DtJuego(){}

DtJuego::DtJuego(string nombre, list<DtCategoria*> categoria, string empresa,  int totalHorasJuego, float puntajePromedio, string descripcion, int costo)
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

void DtJuego::setCategoria(list<DtCategoria*> categoria){
    this->categoria=categoria;
}

void DtJuego::setEmpresa(string empresa){
    this->empresa=empresa;
}

void DtJuego::setPuntajePromedio (float puntajePromedio){
    this->puntajePromedio=puntajePromedio;

}

void DtJuego::setTotalHorasJuego(int totalHorasJuego){
    this->totalHorasJuego=totalHorasJuego;

}

void DtJuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

void DtJuego::setCosto(int totalHorasJuego){
    this->costo=costo;

}

list<DtCategoria*> DtJuego::getCategoria(){
    return this->categoria;
}

string DtJuego::getEmpresa(){
    return this->empresa;
}

float DtJuego::getPuntajePromedio(){
    return this->puntajePromedio;
}

int DtJuego::getTotalHorasJuego(){
    return this->totalHorasJuego;
}

string DtJuego::getDescripcion(){
    return this->descripcion;
}

int DtJuego::getCosto(){
    return this->costo;
}
string DtJuego::getNombre(){
    return this->nombre;
}

void DtJuego::imprimirVerInfo(){
    cout << "♦ Nombre: " << this->nombre << endl;
    cout << "♦ Descripcion: " << this->descripcion << endl;
    cout << "♦ Costo: " << this->costo << endl;
    cout << "♦ Categorias: " << endl;
    for(list<DtCategoria*>::iterator it = this->categoria.begin(); it != this->categoria.end(); ++it){
        cout << "♦ " << "[" << "id: " << (*it)->getId() << "]" << (*it)->getGenero() << "/" << (*it)->getPlataforma() << endl;
    }
    cout << "♦ Empresa: " << this->empresa << endl;
    cout << this->puntajePromedio << endl;
    cout << this->totalHorasJuego << endl;
}

void DtJuego::imprimirSuscripto(){
    cout << "♦ Nombre: " << this->nombre << " - " << "♦ Costo: " << this->costo << endl;
}

DtJuego::~DtJuego(){}
