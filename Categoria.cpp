#include "Categoria.h"

Categoria::Categoria(){}
Categoria::Categoria(string descripcion, string tipoGenero, string tipoPlataforma){
  this->descripcion=descripcion;
  this->tipoGenero=tipoGenero;
  this->tipoPlataforma=tipoPlataforma;
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

string Categoria::getTipoGenero(){
  return this->tipoGenero;
}

void Categoria::setTipoPlataforma(string tipoPlataforma){
  this->tipoPlataforma=tipoPlataforma;
}

string Categoria::getTipoPlataforma(){
  return this->tipoPlataforma;
}

Categoria::~Categoria(){}