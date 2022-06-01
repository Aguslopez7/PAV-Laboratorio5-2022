#include "Suscripcion.h"

Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(string tipoPago,DtFechaHora* fecha){
    this->tipoPago=tipoPago;
    this->fecha=fecha;
}

void Suscripcion:: setTipoPago(string tipoPago){
    this->tipoPago=tipoPago;
}

string Suscripcion:: getTipoPago(){
    return this->tipoPago;
}

void Suscripcion:: setFecha(DtFechaHora* fecha){
    this->fecha=fecha;
}

DtFechaHora* Suscripcion:: getFecha(){
    return this->fecha;
}

/*DtDesarrollador *Desarrollador:: getDtDesarrollador(){
    DtDesarrollador *dt = new DtDesarrollador(this->edad, this->nickname);
    return dt;
}*/

Suscripcion::~Suscripcion(){}