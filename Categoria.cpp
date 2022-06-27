#include "Categoria.h"

Categoria::Categoria(){}

Categoria::Categoria(int id, string descripcion, string tipoGenero, string tipoPlataforma){
  this->id=id;
  this->descripcion=descripcion;
  this->tipoGenero=tipoGenero;
  this->tipoPlataforma=tipoPlataforma;
}

void Categoria::setId(int id){
  this->id=id;
}

void Categoria::setDescripcion(string descripcion){
  this->descripcion=descripcion;
}

string Categoria::getDescripcion(){
  return this->descripcion;
}

void Categoria::setTipoGenero(string tipoGenero){
  this->tipoGenero=tipoGenero;
}

int Categoria::getId(){
  return this->id; 
}

/*int Categoria::getAutoId(){
  id=id+1;
  return id;
}*/

string Categoria::getTipoGenero(){
  return this->tipoGenero;
}

void Categoria::setTipoPlataforma(string tipoPlataforma){
  this->tipoPlataforma=tipoPlataforma;
}

string Categoria::getTipoPlataforma(){
  return this->tipoPlataforma;
}
DtCategoria* Categoria::getDtCategoria(){
  DtCategoria* DtC = new DtCategoria(this->id,this->tipoGenero, this->tipoPlataforma);
  return DtC;
}

Categoria::~Categoria(){}