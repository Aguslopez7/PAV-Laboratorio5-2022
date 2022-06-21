#include "CInfoJuego.h"
#include "ManejadorJuego.h"
#include "DtJuego.h"

list<string> CInfoJuego::listarJuegos(){
    ManejadorJuego *manJuego = ManejadorJuego::getInstancia();
	list<Juego*> juegos = manJuego->listarJuegos();
	list<string> nombreJuegos;
	for (list<Juego*>::iterator it = juegos.begin(); it != juegos.end(); it++){
		nombreJuegos.push_back((*it)->getNombre());
    }
    return nombreJuegos;
}

bool CInfoJuego::hayJuegos(){
    int cont=0;
    bool retorno = true;
    ManejadorJuego* mJ = ManejadorJuego::getInstancia();
    list<Juego*> lista = mJ->listarJuegos();
    for (list<Juego*>::iterator it = lista.begin(); it != lista.end(); it++){
        cont++;
    }
    if(cont >= 1){
        return retorno;
    }else{
        retorno = false;
        return retorno;
    }
}

DtJuego* CInfoJuego::selectJuego(string nombre){
    ManejadorJuego* mc = ManejadorJuego::getInstancia();
    Juego* juego = mc->find(nombre);
    DtJuego* dtc= juego->getDtVideojuego();
    return dtc;
}