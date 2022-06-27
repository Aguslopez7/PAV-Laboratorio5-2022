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
    int id;
    DtFechaHora* fecha;
    int duracion;
    Jugador* jugador;
  public:
    Partida();
    Partida(int id,DtFechaHora* fecha,int duracion,Jugador* jugador);
    void setId(int id);
    int getId();
    DtFechaHora* getFecha();
    void setFecha(DtFechaHora* fecha);
    int getDuracion();
    void setDuracion(int duracion);
    Jugador* getJugador();
    virtual int darTotalHorasParticipantes()=0;
    ~Partida();
};

#endif