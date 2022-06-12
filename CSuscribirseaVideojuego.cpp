#include "CSuscribirseaVideojuego.h"
#include "ManejadorJuego.h"
#include "Sesion.h"
#include "TipoPago.h"
#include "Suscripcion.h"

void CSuscribirseaVideojuego::SuscribirseAVideojuego(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
   // manJue->find(juego); //El jugador ingresa el nombre del juego
   // Suscripcion* suscripcion=new Suscripcion(tipo,costo,fechaHora,u);// El jugador ingresa el tipo. La fecha es la del sistema
    //agregarSuscripcion(suscripcion);
    //add(suscripcion);
}
