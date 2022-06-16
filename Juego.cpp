#include "Juego.h"
#include "Partida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"

using namespace std;

Juego::Juego(){}

Juego::Juego(string nombre, string descripcion,int costo, Usuario* usuario, list<DtCategoria*> categorias){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->usuario=usuario;
}

void Juego::setNombre(string nombre){
    this->nombre=nombre;
}

void Juego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}


void Juego::setUsuario(Usuario* usuario){
    this->usuario=usuario;
}

void Juego::setCosto(int costo){
    this->costo=costo;
}

list<DtCategoria*> Juego::getCategorias(){
    return this->categorias;
}

Usuario* Juego::getUsuario(){
    return this->usuario;
}

string Juego::getDescripcion(){
    return this->descripcion;
}

string Juego::getNombre(){
    return this->nombre;
}


Juego::~Juego(){}