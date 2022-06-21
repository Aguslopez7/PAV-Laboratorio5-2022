#include <ctime>

#include "CSuscribirseaVideojuego.h"
#include "DtFechaHora.h"
#include "ManejadorJuego.h"
#include "Sesion.h"
#include "Juego.h"
#include "Suscripcion.h"

list<DtJuego*> CSuscribirseaVideojuego::listarLosJuegosConSub(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Jugador* jugador = dynamic_cast<Jugador*>(u);
    list<DtJuego*> listDtJuego;
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listJuego = manJue->listarJuegos();
    for(list<Juego*>::iterator it = listJuego.begin(); it != listJuego.end(); ++it){
        if((*it)->tengoSuscripcionJugador(jugador)){
            DtJuego* dtJ = (*it)->getDtVideojuego();
            listDtJuego.push_back(dtJ);
        }
    } 
    return listDtJuego;
}

list<DtJuego*> CSuscribirseaVideojuego::listarLosJuegosSinSub(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Jugador* jugador = dynamic_cast<Jugador*>(u);
    list<DtJuego*> listDtJuego;
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listJuego = manJue->listarJuegos();
    for(list<Juego*>::iterator it = listJuego.begin(); it != listJuego.end(); ++it){
        if(!(*it)->tengoSuscripcionJugador(jugador)){
            DtJuego* dtJ = (*it)->getDtVideojuego();
            listDtJuego.push_back(dtJ);
        }
    } 
    return listDtJuego;
}

bool CSuscribirseaVideojuego::ingresarNombre(string nombre){
    bool retorno = false;
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    
    if (manJue->exist(nombre)){
        this->nombreJuego=nombre;
        retorno = true;
    }
    return retorno;
}

bool CSuscribirseaVideojuego::tieneSuscripcion()
{
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Jugador* jug = dynamic_cast<Jugador*> (u);
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->find(this->nombreJuego);
    bool retorno = juego->tengoSuscripcionJugador(jug);
    return retorno;
}

void CSuscribirseaVideojuego::SuscribirseAVideojuego(TipoPago tipo){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Jugador* jug = dynamic_cast<Jugador*> (u);
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->find(this->nombreJuego);
    time_t t = time(0);
    tm *now = localtime(&t);                //paso fecha del sistema
    DtFechaHora* fechaHora = new DtFechaHora(now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900), now->tm_hour, now->tm_min);
    Suscripcion* suscripcion = new Suscripcion(tipo, juego->getCosto(), fechaHora, jug);
    juego->agregarSuscripcion(suscripcion);
}

void CSuscribirseaVideojuego::cancelar(){
    //se cancela la operacion y se libera la memoria
}