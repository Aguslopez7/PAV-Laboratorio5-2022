#include "ManejadorJuego.h"

ManejadorJuego* ManejadorJuego::instancia = NULL;

ManejadorJuego::ManejadorJuego(){}

ManejadorJuego* ManejadorJuego::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorJuego();
    return instancia;
}

list<Juego*> ManejadorJuego::listarJuegos(){
    list<Juego*> listJuegos;
    for (map<string,Juego*>::iterator it=this->colJuegos.begin(); it!=colJuegos.end(); ++it)
        listJuegos.push_back(it->second);
    return listJuegos;
}

Juego* ManejadorJuego::find(string juego){
  map<string,Juego*>::iterator it = this->colJuegos.find(juego);
  return (it != colJuegos.end())? it->second : NULL;
}

void ManejadorJuego::add(Juego* juego){
    this->colJuegos.insert(pair<string,Juego*>(juego->getNombre(),juego));
}

bool ManejadorJuego::exist(string nombre){ 
  map<string,Juego*>::iterator it = this->colJuegos.find(nombre);
  return (it != this->colJuegos.end());
}

void ManejadorJuego::erase(string juego){
  this->colJuegos.erase(juego);
}

ManejadorJuego::~ManejadorJuego(){}
