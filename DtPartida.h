#ifndef DTPARTIDA
#define DTPARTIDA

#include <string>
#include <iostream>

#include "DtFechaHora.h"
#include "Jugador.h"

using namespace std;

class DtPartida {
  private:
    int id;
    DtFechaHora* fecha;
    int duracion;
    Jugador* jugador;
  public:
    DtPartida();
    DtPartida(int id,DtFechaHora* fecha, int duracion, Jugador* jugador);
    void setId(int id);
    int getId();
    DtFechaHora* getFecha();
    void setFecha(DtFechaHora* fecha);
    int getDuracion();
    Jugador* getJugador();
    void setDuracion(int duracion);
    virtual int darTotalHorasParticipantes()=0;
    ~DtPartida();
};

#endif