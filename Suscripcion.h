#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <iostream>
#include "Suscripcion.h"
#include "DtFechaHora.h"
#include "TipoPago.h"
#include "Jugador.h"

using namespace std;

class Suscripcion{
    private:
        TipoPago tipo;
        int costo;
        DtFechaHora* fecha;
        Jugador* jugador;
    public:
        Suscripcion();
        Suscripcion(TipoPago tipo, int costo, DtFechaHora* fecha, Jugador* jugador);
        void setTipoPago(TipoPago tipo);
        void setCosto(int costo);
        void setFecha(DtFechaHora* fecha);
        TipoPago getTipoPago();
        int getCosto();
        DtFechaHora* getFecha();
        Jugador* getJugador();
        ~Suscripcion();
};

#endif