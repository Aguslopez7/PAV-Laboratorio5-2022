#ifndef FABRICA
#define FABRICA

// Incluir Todas las Interfaces

#include <iostream>
#include "ICAgregarCategoria.h"
#include "ICAgregarVideojuego.h"
#include "ICAltaUsuario.h"
#include "ICCerrarSesion.h"
#include "ICIniciarPartida.h"
#include "ICIniciarSesion.h"
#include "ICSuscribirseaVideojuego.h"
#include "ICInfoJuego.h"
#include "ICEliminarVideojuego.h"
#include "ICAsignarPuntaje.h"
#include "ICCancelarSuscripcion.h"
#include "ICBuscarPorCategoria.h"
#include "ICRankingVideojuego.h"
#include "ICVerPartidas.h"

using namespace std;

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
        ICEliminarVideojuego* getICEliminarVideojuego();
        ICAsignarPuntaje* getICAsignarPuntaje();
        ICCancelarSuscripcion* getICCancelarSuscripcion();
        ICBuscarPorCategoria* getICBuscarPorCategoria();
        ICRankingVideojuego* getICRankingVideojuego();
        ICVerPartidas* getICVerPartidas();
        ~Fabrica();
};
#endif
