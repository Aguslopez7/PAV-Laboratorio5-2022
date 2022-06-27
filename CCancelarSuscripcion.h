#ifndef C_CANCELARSUSCRIPCION
#define C_CANCELARSUSCRIPCION

#include <iostream>
#include <list>
#include "ICCancelarSuscripcion.h"

using namespace std;

class CCancelarSuscripcion : public ICCancelarSuscripcion {
    private:
        string nombreJuego;
    public:
        void cancelarSuscripcion(string nombreJuego);
};

#endif