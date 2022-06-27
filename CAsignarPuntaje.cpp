#include "CAsignarPuntaje.h"

#include "ManejadorJuego.h"
#include "Juego.h"
#include "Estadistica.h"

void CAsignarPuntaje::asignarPuntaje(string nombreJuego, int puntaje){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->getJuego(nombreJuego); 
    Estadistica* estadistica = new Estadistica(puntaje);
    juego->agregarEstadistica(estadistica);   
}
