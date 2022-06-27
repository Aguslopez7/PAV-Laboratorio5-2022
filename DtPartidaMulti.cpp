#include "DtPartidaMulti.h"

DtPartidaMulti::DtPartidaMulti(){}

DtPartidaMulti::DtPartidaMulti(int id, DtFechaHora* fecha, int duracion,Jugador* jugador, bool trasmitidaEnVivo, int cantJugadores):DtPartida(id,fecha,duracion,jugador){
  this->trasmitidaEnVivo=trasmitidaEnVivo;
  this->cantJugadores=cantJugadores;
}

bool DtPartidaMulti::getTrasmitidaEnVivo(){
  return this->trasmitidaEnVivo;
}

void DtPartidaMulti::setTrasmitidaEnVivo(bool trasmitidaEnVivo){
  this->trasmitidaEnVivo=trasmitidaEnVivo;
}

int DtPartidaMulti::darTotalHorasParticipantes(){
  return getDuracion()*this->cantJugadores;
}

int DtPartidaMulti::getCantidadJugadores(){
  return this->cantJugadores;
}

void DtPartidaMulti::setCantidadJugadores(int cantJugadores){
  this->cantJugadores=cantJugadores;
}

void DtPartidaMulti::imprimirMulti(){
  string vivo;
  DtFechaHora* fecha = this->getFecha();
  Jugador* jugador = this->getJugador();
  cout << longTab << COLOR_LG << "┌─────────────────────────────────┐" << endl;
  cout << longTab << "│ ❯ ID: " << this->getId() << endl;
  cout << longTab << "│ ❯ Fecha: " << *fecha << endl;
  cout << longTab << "│ ❯ Duracion: " << this->getDuracion() << endl;
  cout << longTab << "│ ❯ Jugador: " << jugador->getNickname() << endl;
  if(this->getTrasmitidaEnVivo() ==1){
    vivo = "SI";
  }else{
    vivo = "NO";
  }
  cout << longTab << "│ ❯ En vivo: " << vivo << endl;
  cout << longTab << "│ ❯ Cantidad de jugadores: " << this->getCantidadJugadores() << endl;
  cout << longTab << "│ ❯ Total horas jugadas: " << this->darTotalHorasParticipantes() << endl;
  cout << longTab << "└─────────────────────────────────┘" << COLOR_RESET << endl;
}

DtPartidaMulti::~DtPartidaMulti(){}