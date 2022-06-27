#include "Partida.h"

Partida::Partida(){}

Partida::Partida(int id,DtFechaHora* fecha, int duracion, Jugador* jugador){
  this->id=id;
  this->fecha=fecha;
  this->duracion=duracion;
  this->jugador = jugador;
}

void Partida::setId(int id){
  this->id=id;
}

int Partida::getId(){
  return this->id;
}

DtFechaHora* Partida::getFecha(){
  return this->fecha;
}

void Partida::setFecha(DtFechaHora* fecha){
  this->fecha=fecha;
}

int Partida::getDuracion(){
  return this->duracion;
}

void Partida::setDuracion(int duracion){
  this->duracion=duracion;
}

Jugador* Partida::getJugador(){
  return this->jugador;
}

Partida::~Partida(){}