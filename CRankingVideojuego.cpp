#include "CRankingVideojuego.h"
#include "ManejadorJuego.h"

bool CRankingVideojuego::compararPorPuntaje(DtJuego* juego1, DtJuego* juego2){
    return (juego1->getPuntajePromedio() > juego2->getPuntajePromedio());
}

bool CRankingVideojuego::compararPorDuracion(DtJuego* juego1, DtJuego* juego2){
    return (juego1->getTotalHorasJuego() > juego2->getTotalHorasJuego());
}

list<DtJuego*> CRankingVideojuego::listarPorPuntaje(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listaJue = manJue->listarJuegos();
    list<DtJuego*> listaDt;
    for(list<Juego*>::iterator it = listaJue.begin(); it != listaJue.end(); ++it){
        DtJuego* dtJ = (*it)->getDtVideojuego();
        listaDt.push_back(dtJ);
    }
    for(list<DtJuego*>::iterator it = listaDt.begin(); it != listaDt.end(); ++it){
        listaDt.sort(compararPorPuntaje);
    }
    return listaDt;
}

list<DtJuego*> CRankingVideojuego::listarPorDuracion(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listaJue = manJue->listarJuegos();
    list<DtJuego*> listaDt;
    for(list<Juego*>::iterator it = listaJue.begin(); it != listaJue.end(); ++it){
        DtJuego* dtJ = (*it)->getDtVideojuego();
        listaDt.push_back(dtJ);
    }
    for(list<DtJuego*>::iterator it = listaDt.begin(); it != listaDt.end(); ++it){
        listaDt.sort(compararPorDuracion);
    }
     return listaDt;
}