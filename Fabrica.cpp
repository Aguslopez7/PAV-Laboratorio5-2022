#include "Fabrica.h"

// Incluir todos los Controladores

#include "CAgregarCategoria.h"
#include "CAgregarVideojuego.h"
#include "CAltaUsuario.h"
#include "CCerrarSesion.h"
#include "CIniciarPartida.h"
#include "CIniciarSesion.h"
#include "CSuscribirseaVideojuego.h"
#include "CInfoJuego.h"
#include "CEliminarVideojuego.h"
#include "CAsignarPuntaje.h"
#include "CCancelarSuscripcion.h"
#include "CBuscarPorCategoria.h"
#include "CRankingVideojuego.h"
#include "CVerPartidas.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstancia()
{
	if (instancia == NULL)
		instancia = new Fabrica();
	return instancia;
}

ICAgregarCategoria* Fabrica::getICAgregarCategoria()
{
	return new CAgregarCategoria();
}

ICAgregarVideojuego* Fabrica::getICAgregarVideojuego()
{
	return new CAgregarVideojuego();
}

ICAltaUsuario* Fabrica::getICAltaUsuario()
{
	return new CAltaUsuario();
}

ICCerrarSesion* Fabrica::getICCerrarSesion()
{
	return new CCerrarSesion();
}

ICInfoJuego* Fabrica::getICInfoJuego()
{
	return new CInfoJuego();
}

ICIniciarPartida* Fabrica::getICIniciarPartida()
{
	return new CIniciarPartida();
}

ICIniciarSesion* Fabrica::getICIniciarSesion()
{
	return new CIniciarSesion();
}

ICSuscribirseaVideojuego* Fabrica::getICSuscribirseaVideojuego()
{
	return new CSuscribirseaVideojuego();
}

ICEliminarVideojuego* Fabrica::getICEliminarVideojuego(){
	return new CEliminarVideojuego();
}

ICAsignarPuntaje* Fabrica::getICAsignarPuntaje(){
	return new CAsignarPuntaje();
}

ICCancelarSuscripcion* Fabrica::getICCancelarSuscripcion(){
	return new CCancelarSuscripcion();
}

ICBuscarPorCategoria* Fabrica::getICBuscarPorCategoria(){
	return new CBuscarPorCategoria();
}

ICRankingVideojuego* Fabrica::getICRankingVideojuego(){
	return new CRankingVideojuego();
}

ICVerPartidas* Fabrica::getICVerPartidas(){
	return new CVerPartidas();
}

Fabrica::~Fabrica(){}