#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

<<<<<<< HEAD
Sesion* Sesion::getInstancia(){
    if(instancia == NULL){
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}

=======
void Sesion::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
Usuario* Sesion::getUsuario(){
    return this->usuario;
}

<<<<<<< HEAD
=======
Sesion* Sesion::getInstancia(){
    if(instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
Sesion::~Sesion(){}
