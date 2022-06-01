#ifndef PARTIDA
#define PARTIDA

#include <string>
#include <iostream>
#include "DtPartida.h"
#include "Definiciones.h"
#include "DtFechaHora.h"
#include "Jugador.h"

using namespace std;

class Partida {
  private:
    DtFechaHora* fecha;
    int duracion;
    Jugador* jugador;
  public:
    Partida();
    Partida(DtFechaHora* fecha, int duracion, Jugador* jugador);
    DtFechaHora* getFecha();
    void setFecha(DtFechaHora* fecha);
    int getDuracion();
    void setDuracion(int duracion);
    ~Partida();
    virtual int darTotalHorasParticipantes()=0;
};

#endif