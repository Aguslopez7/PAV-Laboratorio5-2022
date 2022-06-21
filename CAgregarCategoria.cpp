#include "CAgregarCategoria.h"
#include "ManejadorCategoria.h"


list<DtCategoria*> CAgregarCategoria::listarDtCategorias(){
    ManejadorCategoria* mCat = ManejadorCategoria::getInstancia();
    list<Categoria*> categorias = mCat->listarCategorias();
    list<DtCategoria*> dtCatList;
    DtCategoria* dtC;
    for (list<Categoria*>::iterator it = categorias.begin(); it != categorias.end(); it++){
        dtC= new DtCategoria((*it)->getId(), (*it)->getTipoGenero(), (*it)->getTipoPlataforma());  // aca no nos devuelve lo que pedimos
		dtCatList.push_back(dtC);
    }
    return dtCatList;
}

bool CAgregarCategoria::hayCategorias(){
    int cont=0;
    bool retorno = true;
    ManejadorCategoria* mC = ManejadorCategoria::getInstancia();
    list<Categoria*> lista = mC->listarCategorias();
    for (list<Categoria*>::iterator it = lista.begin(); it != lista.end(); it++){
        cont++;
    }
    if(cont >= 1){
        return retorno;
    }else{
        retorno = false;
        return retorno;
    }
}

void CAgregarCategoria::solictarDatos(string descripcion, string genero, string plataforma){
    this->descripcion=descripcion;
    this->genero = genero;
    this->plataforma = plataforma;
}

void CAgregarCategoria::confirmarCategoria(){
    ManejadorCategoria* mCat = ManejadorCategoria::getInstancia();
    Categoria*  nuevaCat;
    list<Categoria*> categorias = mCat->listarCategorias();
    int tam = categorias.size();
    int id = tam + 1;
    nuevaCat = new Categoria(id, this->descripcion, this->genero, this->plataforma);
	mCat->add(nuevaCat);
}

DtCategoria* CAgregarCategoria::buscarCat(int id){
    ManejadorCategoria* mC = ManejadorCategoria::getInstancia();
    Categoria* cat = mC->find(id);
    DtCategoria* dtCat = cat->getDtCategoria();
    return dtCat;
}

void CAgregarCategoria::cancelar(){
    // Cancela Operacion y elimina memoria asociada
}