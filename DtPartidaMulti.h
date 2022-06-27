#ifndef DTPARTIDAMULTI
#define DTPARTIDAMULTI

#include <string>
#include <iostream>

#include "DtFechaHora.h"
#include "Jugador.h"
#include "DtPartida.h"

using namespace std;

class DtPartidaMulti : public DtPartida{
  private:
    bool trasmitidaEnVivo;
    int cantJugadores;
  public:
    DtPartidaMulti ();
    DtPartidaMulti (int id,DtFechaHora* fecha, int duracion, Jugador* jugador, bool trasmitidaEnVivo, int cantJugadores);
    bool getTrasmitidaEnVivo();
    void setTrasmitidaEnVivo(bool trasmitidaEnVivo);
    int getCantidadJugadores();
    void setCantidadJugadores(int cantJugadores);
    int darTotalHorasParticipantes();
    void imprimirMulti();
    ~DtPartidaMulti();
};

#endif