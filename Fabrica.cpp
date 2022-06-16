<<<<<<< HEAD


// Incluir todos los Controladores
#include "Fabrica.h"
=======
#include "Fabrica.h"

// Incluir todos los Controladores

>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
#include "CAgregarCategoria.h"
#include "CAgregarVideojuego.h"
#include "CAltaUsuario.h"
#include "CCerrarSesion.h"
#include "CIniciarPartida.h"
#include "CIniciarSesion.h"
#include "CSuscribirseaVideojuego.h"
#include "CInfoJuego.h"

<<<<<<< HEAD

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

=======
Fabrica::Fabrica() {}

Fabrica* Fabrica::instancia = NULL;

>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
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

<<<<<<< HEAD
Fabrica::~Fabrica(){}
=======
Fabrica::~Fabrica() {}
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
