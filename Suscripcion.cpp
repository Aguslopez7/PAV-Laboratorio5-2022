#include "Suscripcion.h"

Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(TipoPago tipo, int costo, DtFechaHora* fecha , Jugador* jugador){
    this->tipo=tipo;
    this->costo=costo;
    this->fecha=fecha;
    this->jugador=jugador;
}

void Suscripcion::setTipoPago(TipoPago tipo){
    this->tipo=tipo;
}

TipoPago Suscripcion::getTipoPago(){
    return this->tipo;
}

void Suscripcion::setCosto(int costo){
    this->costo=costo;
}

int Suscripcion::getCosto(){
    return this->costo;
}

void Suscripcion::setFecha(DtFechaHora* fecha){
    this->fecha=fecha;
}

DtFechaHora* Suscripcion::getFecha(){
    return this->fecha;
}

Jugador* Suscripcion::getJugador(){
    return this->jugador;
}
Suscripcion::~Suscripcion(){}