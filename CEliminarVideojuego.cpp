#include <iostream>
#include <list>

#include "ManejadorJuego.h"
#include "CEliminarVideojuego.h"
#include "Juego.h"
#include "DtJuego.h"
#include "Sesion.h"

list<DtJuego*> CEliminarVideojuego::listarJuegosDev(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Desarrollador* dev = dynamic_cast<Desarrollador*> (u);
    list<DtJuego*> listDtJuego;
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listJuego = manJue->listarJuegos();
    for(list<Juego*>::iterator it = listJuego.begin(); it != listJuego.end(); ++it){
        if ((*it)->getDesarrollador() == dev){
            DtJuego* dtJ = (*it)->getDtVideojuego();
            listDtJuego.push_back(dtJ);
        }
    }
    return listDtJuego;
}

void CEliminarVideojuego::seleccionarJuego(string nombre){
    this->nombreJuego=nombre;
}

void CEliminarVideojuego::eliminarVideojuego(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* jue = manJue->getJuego(this->nombreJuego);
    manJue->removerJuego(jue);
    jue->~Juego();    
}

void CEliminarVideojuego::cancelar(){
    //cancela la operacion y elimina la memoria asociada
}