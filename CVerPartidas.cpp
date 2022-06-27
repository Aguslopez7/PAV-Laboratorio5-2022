#include <list>
#include <iostream>

#include "CVerPartidas.h"
#include "Juego.h"
#include "DtJuego.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "DtPartida.h"
#include "DtPartidaIndi.h"
#include "DtPartidaMulti.h"
#include "ManejadorJuego.h"

list<DtJuego*> CVerPartidas::listarLosJuegos(){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<DtJuego*> listDtJuego;
    list<Juego*> listJuego = manJue->listarJuegos();
    for (list<Juego*>::iterator it = listJuego.begin(); it != listJuego.end(); ++it){
            DtJuego* dtJ = (*it)->getDtVideojuego();
            listDtJuego.push_back(dtJ);
    }
    return listDtJuego;
}

bool CVerPartidas::checkVideojuego(string nombreJuego)
{
    ManejadorJuego* mJ = ManejadorJuego::getInstancia();
    return mJ->exist(nombreJuego);
}

list<DtPartida*> CVerPartidas::verPartidas(string nombreJuego){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->getJuego(nombreJuego);
    list<Partida*> listaPartida = juego->getPartidas();
    list<DtPartida*> listaDtPartida;
    DtPartida* dtP;
    for(list<Partida*>::iterator it = listaPartida.begin(); it != listaPartida.end(); ++it){
        if ( PartidaIndividual* pI = dynamic_cast <PartidaIndividual*> (*it)){
            dtP = new DtPartidaIndi(pI->getId(),pI->getFecha(), pI->getDuracion(), pI->getJugador(), pI->getContinuaPartidaAnterior());
            listaDtPartida.push_back(dtP);
        }else{
            if(PartidaMultijugador* pM = dynamic_cast <PartidaMultijugador*> (*it)){
                dtP = new DtPartidaMulti(pM->getId(),pM->getFecha(),pM->getDuracion(),pM->getJugador(),pM->getTrasmitidaEnVivo(),pM->getCantidadJugadores());
                listaDtPartida.push_back(dtP);
            }
        }
    }
    return listaDtPartida;
}