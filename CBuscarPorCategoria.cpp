#include "CBuscarPorCategoria.h"
#include "ManejadorJuego.h"
#include "Categoria.h"
#include "ManejadorCategoria.h"
#include "Juego.h"

 bool CBuscarPorCategoria::existeCategoria(int idCat){
    bool uwu = false;
    ManejadorCategoria* manCat = ManejadorCategoria::getInstancia();
    if (manCat->existeCat(idCat)){
        uwu= true;
    }
    return uwu;
}

Categoria* CBuscarPorCategoria::dameCategoria(int idCat){
    ManejadorCategoria* manCat = ManejadorCategoria::getInstancia();
    Categoria* cat = manCat->find(idCat);
    return cat;
}

list<DtJuego*> CBuscarPorCategoria::buscarPorCategoria(int catId){
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    list<Juego*> listaJuegos = manJue->listarJuegos();
    list<DtJuego*> listaDtJuego;
    for(list<Juego*>::iterator it = listaJuegos.begin(); it != listaJuegos.end(); ++it){
        if((*it)->tengoCategoria(catId)){
            DtJuego* dtJ = (*it)->getDtVideojuego();
            listaDtJuego.push_back(dtJ);
        }
    }
    return listaDtJuego;
}