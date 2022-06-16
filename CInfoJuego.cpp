#include "CInfoJuego.h"
#include "ManejadorJuego.h"
#include "DtJuego.h"

list<string> CInfoJuego::listarJuegos(){
    ManejadorJuego *manJuego = ManejadorJuego::getInstancia();
	list<Juego*> juegos = manJuego->listarJuegos();
	list<string> nombreJuegos;

	for (list<Juego*>::iterator it = juegos.begin(); it != juegos.end(); it++)
		nombreJuegos.push_back((*it)->getNombre());

    return nombreJuegos;
}

DtJuego* CInfoJuego::selectJuego(string nombre){
    this->nombre = nombre;
    ManejadorJuego* mc = ManejadorJuego::getInstancia();
    Juego* juego = mc->find(nombre);
    DtJuego* dtc = new DtJuego(dtc->getNombre(),dtc->getCategoria(),dtc->getEmpresa(),dtc->getTotalHorasJuego(),dtc->getPuntajePromedio(),dtc->getDescripcion(),dtc->getCosto());
    return dtc;
}