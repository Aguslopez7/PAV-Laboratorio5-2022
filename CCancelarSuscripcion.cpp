#include "CCancelarSuscripcion.h"
#include "ManejadorJuego.h"

void CCancelarSuscripcion::cancelarSuscripcion(string nombreJuego){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->getJuego(nombreJuego); 
    juego->cancelarSuscripcion();   
}