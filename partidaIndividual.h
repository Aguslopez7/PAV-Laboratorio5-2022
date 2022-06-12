#ifndef PARTIDAINVIDIUAL
#define PARTIDAINVIDIUAL

#include "Partida.h"

class PartidaIndividual : public Partida{
  private:
    bool continuaPartidaAnterior;
  public:
    PartidaIndividual ();
    PartidaIndividual (DtFechaHora* fecha, int duracion, Jugador* jugador, bool continuaPartidaAnterior);
    void setContinuaPartidaAnterior(bool continuaPartidaAnterior);
    bool getContinuaPartidaAnterior();
    int darTotalHorasParticipantes();
    ~PartidaIndividual ();
};

#endif