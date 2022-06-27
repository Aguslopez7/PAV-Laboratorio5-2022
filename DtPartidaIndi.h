#ifndef DtPartidaIndiI
#define DtPartidaIndiI

#include <string>
#include <iostream>

#include "DtFechaHora.h"
#include "Jugador.h"
#include "DtPartida.h"

using namespace std;

class DtPartidaIndi : public DtPartida{
  private:
    bool continuaPartidaAnterior;
  public:
    DtPartidaIndi ();
    DtPartidaIndi (int id,DtFechaHora* fecha, int duracion, Jugador* jugador, bool continuaPartidaAnterior);
    void setContinuaPartidaAnterior(bool continuaPartidaAnterior);
    bool getContinuaPartidaAnterior();
    int darTotalHorasParticipantes();
    void imprimirIndi();
    ~DtPartidaIndi();
};

#endif