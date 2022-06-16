#ifndef DTPARTIDA
#define DTPARTIDA

#include <string>
#include <iostream>
#include "DtFechaHora.h"

using namespace std;

class DtPartida {
  private:
    DtFechaHora* fecha;
    int duracion;
  public:
    DtPartida();
    DtPartida(int duracion, DtFechaHora* fecha);
    void setDuracion(int duracion);
    void setFechaHora(DtFechaHora* fecha);
    string getDuracion();
    string getDtFechaHora();
    ~DtPartida();
};

#endif