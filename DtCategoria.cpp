#include "DtCategoria.h"
#include "Definiciones.h"

<<<<<<< HEAD
DtCategoria::DtCategoria(int id, string tipoGenero, string tipoPlataforma){
    this->id=id;
    this->tipoGenero=tipoGenero;
    this->tipoPlataforma=tipoPlataforma;
}

void DtCategoria::setId(int id){
    this->id = id;
}

=======

DtCategoria::DtCategoria(int id, string tipoGenero, string tipoPlataforma){
    this->id=id;
    this->tipoGenero=tipoGenero;
    this->tipoPlataforma=tipoPlataforma;
}

void DtCategoria::setId(int id){
    this->id = id;
}

>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca

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
<<<<<<< HEAD
    cout << longTab << "    ♦ " << this->tipoGenero << " / " << this->tipoPlataforma << endl;
=======
    cout << this->tipoGenero << " / " << this->tipoPlataforma << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
}

DtCategoria::~DtCategoria(){}