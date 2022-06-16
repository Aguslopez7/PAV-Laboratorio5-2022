#ifndef PARTIDAINVIDIUAL
#define PARTIDAINVIDIUAL

#include "Partida.h"
<<<<<<< HEAD

using namespace std;
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

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