#ifndef C_SUSCRIBIRSEAVIDEOJUEGO
#define C_SUSCRIBIRSEAVIDEOJUEGO

#include <iostream>
#include <list>

#include "DtJuego.h"
#include "ICSuscribirseaVideojuego.h"
#include "TipoPago.h"


using namespace std;

class CSuscribirseaVideojuego : public ICSuscribirseaVideojuego {
    private:
        string nombreJuego;
        int costo;
        TipoPago tipoPago;
    public:
        list<DtJuego*> listarLosJuegosConSub();
        list<DtJuego*> listarLosJuegosSinSub();
        bool ingresarNombre(string nombre);
        bool tieneSuscripcion();
        void SuscribirseAVideojuego(TipoPago tipo); 
        void cancelar();
};

#endif