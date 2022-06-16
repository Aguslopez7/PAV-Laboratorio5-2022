#ifndef C_CERRARSESION
#define C_CERRARSESION

#include "ICCerrarSesion.h"
#include "Sesion.h"

using namespace std;

class CCerrarSesion : public ICCerrarSesion {
   public:
    void cerrarSesion();
};

#endif