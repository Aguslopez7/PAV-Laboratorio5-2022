#include "PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(){}

PartidaMultijugador::PartidaMultijugador(int id, DtFechaHora* fecha, int duracion,Jugador* jugador, bool trasmitidaEnVivo, int cantJugadores):Partida(id,fecha,duracion,jugador){
  this->trasmitidaEnVivo=trasmitidaEnVivo;
  this->cantJugadores=cantJugadores;

}

bool PartidaMultijugador::getTrasmitidaEnVivo(){
  return this->trasmitidaEnVivo;
}

void PartidaMultijugador::setTrasmitidaEnVivo(bool trasmitidaEnVivo){
  this->trasmitidaEnVivo=trasmitidaEnVivo;
}

int PartidaMultijugador::darTotalHorasParticipantes(){
  return getDuracion()*this->cantJugadores;
}

int PartidaMultijugador::getCantidadJugadores(){
  return this->cantJugadores;
}

void PartidaMultijugador::setCantidadJugadores(int cantJugadores){
  this->cantJugadores=cantJugadores;
}

PartidaMultijugador::~PartidaMultijugador(){}