#ifndef FABRICA
#define FABRICA

// Incluir Todas las Interfaces

#include "ICAgregarCategoria.h"
#include "ICAgregarVideojuego.h"
#include "ICAltaUsuario.h"
#include "ICCerrarSesion.h"
#include "ICIniciarPartida.h"
#include "ICIniciarSesion.h"
#include "ICSuscribirseaVideojuego.h"
#include "ICInfoJuego.h"

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
