#include "Estadistica.h"

Estadistica::Estadistica(){}
Estadistica::Estadistica(int puntaje){
    this->puntaje=puntaje;
}

void Estadistica::setPuntaje(int puntaje){
    this->puntaje=puntaje;
}

int Estadistica:: getPuntaje(){
    return this->puntaje;
}

Estadistica::~Estadistica(){}

