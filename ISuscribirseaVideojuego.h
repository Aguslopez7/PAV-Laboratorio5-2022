#ifndef ISUSCRIBIRSEAVIDEOJUEGO
#define ISUSCRIBIRSEAVIDEOJUEGO

#include <iostream>

#include "DtJuego.h"

using namespace std;

class ISuscribirseaVideojuego {
   public:
    virtual void listarVideoJuegos(DtJuego) = 0;
    virtual void seleccionJuego(string nombre) = 0;
    virtual void suscribirse(string tipoPago) = 0;
    virtual void confirmarCompra() = 0;
    virtual void cancelar() = 0;
};

#endif