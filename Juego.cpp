#include "Juego.h"
#include "Partida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"

using namespace std;

Juego::Juego(){}

Juego::Juego(string nombre, string descripcion,int puntaje,int totalHoras, Usuario* usuario, DtCategoria* categoria){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->puntaje=puntaje;
    this->totalHoras=totalHoras;
}

void Juego::setNombre(string nombre){
    this->nombre=nombre;
}

void Juego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

void Juego::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}
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
}

Usuario* Juego::getUsuario(){
    return this->usuario;
}

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

//agregarSuscripcion(Suscripcion)

Juego::~Juego(){}