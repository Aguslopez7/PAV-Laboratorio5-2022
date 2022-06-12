#include "ManejadorCategoria.h"

ManejadorCategoria* ManejadorCategoria::instancia = NULL;

ManejadorCategoria::ManejadorCategoria(){}

ManejadorCategoria* ManejadorCategoria::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorCategoria();
    return instancia;
}

list<Categoria*> ManejadorCategoria::listarCategorias(){
    list<Categoria*> listCategorias;
    for (map<int,Categoria*>::iterator it=this->colCategorias.begin(); it!=colCategorias.end(); ++it)
        listCategorias.push_back(it->second);
    return listCategorias;
}

Categoria* ManejadorCategoria::find(int id)
{
	map<int, Categoria*>::iterator it = this->colCategorias.find(id);
	return (it != colCategorias.end())? it->second : NULL;
}

void ManejadorCategoria::add(Categoria* categoria)
{
	this->colCategorias.insert(pair<int, Categoria*>(categoria->getId(), categoria));
}

void ManejadorCategoria::erase(int id)
{
	this->colCategorias.erase(id);
}

ManejadorCategoria::~ManejadorCategoria(){}