#ifndef FABRICA
#define FABRICA

// Incluir Todas las Interfaces

<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
#include "ICAgregarCategoria.h"
#include "ICAgregarVideojuego.h"
#include "ICAltaUsuario.h"
#include "ICCerrarSesion.h"
#include "ICIniciarPartida.h"
#include "ICIniciarSesion.h"
#include "ICSuscribirseaVideojuego.h"
#include "ICInfoJuego.h"

<<<<<<< HEAD
using namespace std;

=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        ICAgregarCategoria* getICAgregarCategoria();
        ICAgregarVideojuego* getICAgregarVideojuego();
        ICAltaUsuario * getICAltaUsuario();
        ICCerrarSesion* getICCerrarSesion();
        ICInfoJuego * getICInfoJuego();
        ICIniciarPartida* getICIniciarPartida();
        ICIniciarSesion* getICIniciarSesion();
        ICSuscribirseaVideojuego* getICSuscribirseaVideojuego();
        ~Fabrica();
};
#endif
