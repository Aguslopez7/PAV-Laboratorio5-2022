#include "CAgregarCategoria.h"
#include "ManejadorCategoria.h"
#include "DtCategoria.h"

list<DtCategoria*> CAgregarCategoria::listCategorias(){
    ManejadorCategoria* mCat = ManejadorCategoria::getInstancia();
    return mCat->listarCategorias();    
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