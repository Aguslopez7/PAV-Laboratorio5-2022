#include "Juego.h"
#include "Sistema.h"
#include "Partida.h"
#include "DtPartida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"

using namespace std;

Juego::Juego(){}

Juego::Juego(string nombre, string descripcion, int puntaje, int totalPartidas){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->puntaje=puntaje;
    this->totalPartidas=totalPartidas;
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

void Juego::setTotalPartidas(int totalPartidas){
    this->totalPartidas=totalPartidas;
}

int Juego::getTotalPartidas(){
    return this->totalPartidas;
}

string Juego::getDescripcion(){
    return this->descripcion;
}

int Juego::getPuntaje(){
    return this->puntaje;
}

string Juego::getNombre(){
    return this->nombre;
}

int Juego:: getTopePartidaVJ(){
    return this->topePartidaVJ;
}

/*DtJuego* Juego::getDtVideoJuego(){
    int totalHorasDeJuego=0;
    for(int i=0; i< this->topePartidaVJ; i++)
        totalHorasDeJuego = totalHorasDeJuego + this->partidas[i]->darTotalHorasParticipantes();
    DtJuego *dt = new DtJuego(this->genero, this->nombre, totalHorasDeJuego);
    return dt;
}*/

void Juego::addPartida(Partida* p){
    this->partidas[this->topePartidaVJ]=p;
    this->topePartidaVJ++;
}

Partida** Juego::getPartida(int& cantPartidas){
    cantPartidas = this->topePartidaVJ;
    return this->partidas;
}

Juego::~Juego(){}