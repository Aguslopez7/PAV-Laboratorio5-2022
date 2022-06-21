#ifndef ISUSCRIBIRSEAVIDEOJUEGO
#define ISUSCRIBIRSEAVIDEOJUEGO

#include <iostream>
#include "DtJuego.h"
#include "TipoPago.h"

using namespace std;

class ICSuscribirseaVideojuego {
   public:
    virtual list<DtJuego*> listarLosJuegosConSub() = 0;
    virtual list<DtJuego*> listarLosJuegosSinSub() = 0;
    virtual bool ingresarNombre(string nombre) = 0;
    virtual bool tieneSuscripcion() = 0;
    virtual void SuscribirseAVideojuego(TipoPago tipo) = 0;
    virtual void cancelar() = 0;
};

#endif