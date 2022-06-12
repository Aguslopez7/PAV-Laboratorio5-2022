#include "CAgregarVideojuego.h"
#include "ManejadorJuego.h"
#include "ManejadorCategoria.h"
#include "Sesion.h"
#include "DtJuego.h"

void CAgregarVideojuego::solicitarInfo(string nombre, string descripcion, int costo, DtCategoria* dtCategoria){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->dtCategoria=dtCategoria;
}

list<DtJuego*> CAgregarVideojuego::listJuegos(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
	return manJue->listarJuegos();     //devolves un list<juego*> y no list<dtjuego*>
}

void CAgregarVideojuego::confirmarJuego(){
    ManejadorCategoria* manCat = ManejadorCategoria::getInstancia();
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Sesion* sesi = Sesion::getInstancia();
    Usuario* u = sesi->getUsuario();
    Juego* juego = new Juego(this->nombre, this->descripcion, this->costo,u, this->dtCategoria);
    manJue->add(juego);
}

void CAgregarVideojuego::cancelar(){
    // se libera la memoria
}