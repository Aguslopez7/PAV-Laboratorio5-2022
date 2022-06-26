#include "PartidaIndividual.h"

PartidaIndividual::PartidaIndividual(){}

PartidaIndividual::PartidaIndividual(int id,DtFechaHora* fecha, int duracion,Jugador* jugador, bool continuaPartidaAnterior):Partida(id,fecha,duracion,jugador){
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