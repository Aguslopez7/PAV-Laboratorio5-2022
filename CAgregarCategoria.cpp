#include "CAgregarCategoria.h"
#include "ManejadorCategoria.h"


list<DtCategoria*> CAgregarCategoria::listarDtCategorias(){
    ManejadorCategoria* mCat = ManejadorCategoria::getInstancia();
    list<Categoria*> categorias = mCat->listarCategorias();
    list<DtCategoria*> dtCatList;
    DtCategoria* dtC;
    for (list<Categoria*>::iterator it = categorias.begin(); it != categorias.end(); it++){
        dtC= new DtCategoria((*it)->getTipoGenero(), (*it)->getTipoPlataforma());
		dtCatList.push_back(dtC);
    }
    return dtCatList;
}

void CAgregarCategoria::solictarDatos(int id, string genero, string plataforma){
    this->id = id;
    this->genero = genero;
    this->plataforma = plataforma;
}

void CAgregarCategoria::confirmarCategoria(){
    ManejadorCategoria* mCat = ManejadorCategoria::getInstancia();
	Categoria* categoria = mCat->find(this->id);
	mCat->add(categoria);
}

void CAgregarCategoria::cancelar(){
    // Cancela Operacion y elimina memoria asociada
}