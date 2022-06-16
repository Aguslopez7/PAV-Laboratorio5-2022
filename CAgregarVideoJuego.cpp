#include "CAgregarVideojuego.h"
#include "ManejadorJuego.h"
#include "ManejadorCategoria.h"
#include "Sesion.h"
#include "Usuario.h"


void CAgregarVideojuego::solicitarInfo(string nombre, string descripcion, int costo){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
}


void CAgregarVideojuego::agregarCategoria(DtCategoria* dt){
    this->listDtCategorias.push_back(dt);
}

void CAgregarVideojuego::confirmarJuego(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Sesion* sesi = Sesion::getInstancia();  
    Usuario* u = sesi->getUsuario();
    Juego* juego = new Juego(this->nombre, this->descripcion, this->costo, u, this->listDtCategorias);
    manJue->add(juego);
}

void CAgregarVideojuego::cancelar(){
    // se libera la memoria
}