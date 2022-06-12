#ifndef C_CERRARSESION
#define C_CERRARSESION

#include "ICCerrarSesion.h"
#include "Sesion.h"

class CCerrarSesion : public ICCerrarSesion {
   public:
    void cerrarSesion();
};

#endif