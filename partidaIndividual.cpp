#include "partidaIndividual.h"

PartidaIndividual::PartidaIndividual(){}

PartidaIndividual::PartidaIndividual(DtFechaHora* fecha, int duracion,Jugador* jugador, bool continuaPartidaAnterior):Partida(fecha,duracion,jugador){
  this->continuaPartidaAnterior=continuaPartidaAnterior;
}

bool PartidaIndividual::getContinuaPartidaAnterior(){
  return this->continuaPartidaAnterior;
}

void PartidaIndividual::setContinuaPartidaAnterior(bool continuaPartidaAnterior){
  this->continuaPartidaAnterior=continuaPartidaAnterior;
}

int PartidaIndividual::darTotalHorasParticipantes(){
  return getDuracion();
}

PartidaIndividual::~PartidaIndividual (){}