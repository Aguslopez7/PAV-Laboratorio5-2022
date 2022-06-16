#include "DtPartida.h"

DtPartida::DtPartida(){}

DtPartida::DtPartida(int duracion, DtFechaHora* fecha){
    this->duracion;
    this->fecha;
}

void DtPartida::setDuracion(int duracion){
    this->duracion = duracion;
}

void DtPartida::setDtFechaHora(DtFechaHora* fecha){
    this->fecha = fecha;
}

int DtPartida::getDuracion(){
    return this->duracion;
}

string DtPartida::getDtFechaHora(){
    return this->fecha;
}

DtPartida::~DtPartida(){}