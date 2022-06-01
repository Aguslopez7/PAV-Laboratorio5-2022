#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <iostream>
#include <string>
#include "Suscripcion.h"
#include "DtFechaHora.h"
using namespace std;

class Suscripcion{
    private:
        string tipoPago;
        DtFechaHora* fecha;
    public:
        Suscripcion();
        Suscripcion(string tipoPago,DtFechaHora* fechaHora);
        void setTipoPago(string tipoPago);
        string getTipoPago();
        void setFecha(DtFechaHora* fecha);
        DtFechaHora* getFecha();
        ~Suscripcion();
};

#endif