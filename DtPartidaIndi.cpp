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
<<<<<<< HEAD
  string cont;
  DtFechaHora* fecha = this->getFecha();
  Jugador* jugador = this->getJugador();
  cout << longTab << COLOR_LG << " ❯ ID: " << this->getId() << endl;
  cout << longTab << " ❯ Fecha: " << *fecha << endl;
  cout << longTab << " ❯ Duracion: " << this->getDuracion() << endl;
  cout << longTab << " ❯ Jugador: " << jugador->getNickname() << endl;
=======
  system("clear");
  string cont;
  DtFechaHora* fecha = this->getFecha();
  Jugador* jugador = this->getJugador();
  cout << longTab << "┌───────────────────────────────────────" << endl;
  cout << longTab << "│ ❯ Fecha: " << *fecha << endl;
  cout << longTab << "│ ❯ Duracion: " << this->getDuracion() << endl;
  cout << longTab << "│ ❯ Jugador: " << jugador->getNickname() << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
  if(this->getContinuaPartidaAnterior() == 1){
    cont= "SI";
  }else{
    cont="NO";
  }
<<<<<<< HEAD
  cout << longTab << " ❯ Continuacion: " << cont << endl;
  cout << longTab << " ❯ Total horas jugadas: " << this->darTotalHorasParticipantes() << COLOR_RESET << endl;
=======
  cout << longTab << "│ ❯ Continuacion: " << cont << endl;
  cout << longTab << "│ ❯ Total horas jugadas: " << this->darTotalHorasParticipantes() << endl;
  cout << longTab << "└───────────────────────────────────────" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
}

DtPartidaIndi::~DtPartidaIndi (){}