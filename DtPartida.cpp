#include "DtPartida.h"

DtPartida::DtPartida(){}

DtPartida::DtPartida(int id,DtFechaHora* fecha, int duracion, Jugador* jugador){
    this->id=id;
    this->fecha=fecha;
    this->duracion=duracion;
    this->jugador=jugador;
}

void DtPartida::setId(int id){
  this->id=id;
}

int DtPartida::getId(){
  return this->id;
}

void DtPartida::setDuracion(int duracion){
    this->duracion = duracion;
}

void DtPartida::setFecha(DtFechaHora* fecha){
    this->fecha = fecha;
}

int DtPartida::getDuracion(){
    return this->duracion;
}

DtFechaHora* DtPartida::getFecha(){
    return this->fecha;
}

Jugador* DtPartida::getJugador(){
    return this->jugador;
}

DtPartida::~DtPartida(){}