#include "Suscripcion.h"

Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(TipoPago tipo,int costo,DtFechaHora* fecha, Usuario* usuario){
    this->tipo=tipo;
    this->costo=costo;
    this->fecha=fecha;
    this->usuario=usuario;
}

void Suscripcion:: setTipoPago(TipoPago tipo){
    this->tipo=tipo;
}

TipoPago Suscripcion:: getTipoPago(){
    return this->tipo;
}

void Suscripcion:: setCosto(int costo){
    this->costo=costo;
}

int Suscripcion:: getCosto(){
    return this->costo;
}

void Suscripcion:: setFecha(DtFechaHora* fecha){
    this->fecha=fecha;
}

DtFechaHora* Suscripcion:: getFecha(){
    return this->fecha;
}

void Suscripcion:: setUsuario(Usuario* usuario){
    this->usuario=usuario;
}

Usuario* Suscripcion:: getUsuario(){
    return this->usuario;
}

Suscripcion::~Suscripcion(){}