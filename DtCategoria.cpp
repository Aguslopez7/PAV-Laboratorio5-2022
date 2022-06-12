#include "DtCategoria.h"

DtCategoria::DtCategoria(){}

DtCategoria::DtCategoria(string genero, string tipoPlataforma){
    this->tipoGenero;
    this->tipoPlataforma;
}

void DtCategoria::setGenero(string genero){
    this->tipoGenero = tipoGenero;
}

void DtCategoria::setPlataforma(string tipoPlataforma){
    this->tipoPlataforma = tipoPlataforma;
}

string DtCategoria::getGenero(){
    return this->tipoGenero;
}

string DtCategoria::getPlataforma(){
    return this->tipoPlataforma;
}

DtCategoria::~DtCategoria(){}