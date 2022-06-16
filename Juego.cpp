#include "Juego.h"
#include "Partida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"

using namespace std;

Juego::Juego(){}

<<<<<<< HEAD
Juego::Juego(string nombre, string descripcion,int costo, Usuario* usuario, list<DtCategoria*> categorias){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->usuario=usuario;
=======
Juego::Juego(string nombre, string descripcion,int puntaje,int totalHoras, Usuario* usuario, DtCategoria* categoria){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->puntaje=puntaje;
    this->totalHoras=totalHoras;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
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
<<<<<<< HEAD

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
=======
void Juego::setTotalHoras(int totalHoras){
    this->totalHoras=totalHoras;
}

void Juego::setUsuario(Usuario* usuario){
    this->usuario=usuario;
}

void Juego::setCategoria(DtCategoria* categoria){
    this->categoria=categoria;
}

DtCategoria* Juego::getCategoria(){
    return this->categoria;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
}

Usuario* Juego::getUsuario(){
    return this->usuario;
}

<<<<<<< HEAD
=======
int Juego::getPuntaje(){
    return this->puntaje;
}
int Juego::getTotalHoras(){
    return this->totalHoras;
} 

string Juego::getDescripcion(){
    return this->descripcion;
}

string Juego::getNombre(){
    return this->nombre;
}
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

//agregarSuscripcion(Suscripcion)

Juego::~Juego(){}