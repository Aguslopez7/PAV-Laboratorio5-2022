#include "DtCategoria.h"
#include "Definiciones.h"

DtCategoria::DtCategoria(int id, string tipoGenero, string tipoPlataforma){
    this->id=id;
    this->tipoGenero=tipoGenero;
    this->tipoPlataforma=tipoPlataforma;
}

void DtCategoria::setId(int id){
    this->id = id;
}


void DtCategoria::setGenero(string tipoGenero){
    this->tipoGenero = tipoGenero;
}

void DtCategoria::setPlataforma(string tipoPlataforma){
    this->tipoPlataforma = tipoPlataforma;
}

int DtCategoria::getId(){
    return this->id;
}

string DtCategoria::getGenero(){
    return this->tipoGenero;
}

string DtCategoria::getPlataforma(){
    return this->tipoPlataforma;
}

void DtCategoria::imprimirPar(){
    cout << longTab << "    ♦ " << this->tipoGenero << " / " << this->tipoPlataforma << endl;
}

DtCategoria::~DtCategoria(){}