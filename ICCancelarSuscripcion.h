#ifndef IC_CANCELARSUSCRIPCION
#define IC_CANCELARSUSCRIPCION

#include <iostream>
#include <list>

using namespace std;

class ICCancelarSuscripcion {
    public:
        virtual void cancelarSuscripcion(string nombreJuego) = 0;
};

#endif