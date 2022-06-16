#include "CAgregarVideojuego.h"
#include "ManejadorJuego.h"
#include "ManejadorCategoria.h"
#include "Sesion.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
    manJue->add(juego);
}

void CAgregarVideojuego::cancelar(){
    // se libera la memoria
}