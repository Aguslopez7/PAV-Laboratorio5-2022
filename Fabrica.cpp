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

Fabrica::Fabrica() {}

Fabrica* Fabrica::instancia = NULL;

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

Fabrica::~Fabrica() {}