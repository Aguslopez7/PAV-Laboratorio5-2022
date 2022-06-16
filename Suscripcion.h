#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <iostream>
#include "Suscripcion.h"
#include "DtFechaHora.h"
#include "TipoPago.h"
#include "Usuario.h"

using namespace std;

class Suscripcion{
    private:
    TipoPago tipo;
    int costo;
    DtFechaHora* fecha;
    Usuario* usuario;

    public:
    Suscripcion();
    Suscripcion(TipoPago tipo,int costo,DtFechaHora* fecha, Usuario* usuario);
    void setTipoPago(TipoPago tipo);
    void setCosto(int costo);
    void setFecha(DtFechaHora* fecha);
    void setUsuario(Usuario* usuario);
    TipoPago getTipoPago();
    int getCosto();
    DtFechaHora* getFecha();
    Usuario* getUsuario();
    ~Suscripcion();
};

#endif