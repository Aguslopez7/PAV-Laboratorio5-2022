#ifndef PARTIDA
#define PARTIDA

#include <string>
#include <iostream>
#include "Definiciones.h"
#include "DtFechaHora.h"
#include "Jugador.h"
//#include "DtPartida.h"

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