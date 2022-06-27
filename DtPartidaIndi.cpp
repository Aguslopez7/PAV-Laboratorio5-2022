#include "DtPartidaIndi.h"

DtPartidaIndi::DtPartidaIndi(){}

DtPartidaIndi::DtPartidaIndi(int id,DtFechaHora* fecha, int duracion,Jugador* jugador, bool continuaPartidaAnterior):DtPartida(id,fecha,duracion,jugador){
  this->continuaPartidaAnterior=continuaPartidaAnterior;
}

bool DtPartidaIndi::getContinuaPartidaAnterior(){
  return this->continuaPartidaAnterior;
}

void DtPartidaIndi::setContinuaPartidaAnterior(bool continuaPartidaAnterior){
  this->continuaPartidaAnterior=continuaPartidaAnterior;
}

int DtPartidaIndi::darTotalHorasParticipantes(){
  return getDuracion();
}

void DtPartidaIndi::imprimirIndi(){
  string cont;
  DtFechaHora* fecha = this->getFecha();
  Jugador* jugador = this->getJugador();
  cout << longTab << COLOR_LG << " ❯ ID: " << this->getId() << endl;
  cout << longTab << " ❯ Fecha: " << *fecha << endl;
  cout << longTab << " ❯ Duracion: " << this->getDuracion() << endl;
  cout << longTab << " ❯ Jugador: " << jugador->getNickname() << endl;
  if(this->getContinuaPartidaAnterior() == 1){
    cont= "SI";
  }else{
    cont="NO";
  }
  cout << longTab << " ❯ Continuacion: " << cont << endl;
  cout << longTab << " ❯ Total horas jugadas: " << this->darTotalHorasParticipantes() << COLOR_RESET << endl;
}

DtPartidaIndi::~DtPartidaIndi (){}