#include "Juego.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "ManejadorJuego.h"
#include "Sesion.h"
#include "Jugador.h"


using namespace std;

Juego::Juego(){}

Juego::Juego(string nombre, string descripcion,int costo, Desarrollador* dev, list<Categoria*> categorias){
    this->nombre=nombre;
    this->descripcion=descripcion;
    this->costo=costo;
    this->dev=dev;
    this->categorias=categorias;
}

void Juego::setNombre(string nombre){
    this->nombre=nombre;
}

void Juego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}


void Juego::setDesarrollador(Desarrollador* dev){
    this->dev=dev;
}

void Juego::setCosto(int costo){
    this->costo=costo;
}

int Juego::getCosto(){
    return this->costo;
}

list<Categoria*> Juego::getCategorias(){
    return this->categorias;
}

list<Partida*> Juego::getPartidas(){
    return this->partidas;
}

Desarrollador* Juego::getDesarrollador(){
    return this->dev;
}

string Juego::getDescripcion(){
    return this->descripcion;
}

string Juego::getNombre(){
    return this->nombre;
}

DtJuego* Juego::getDtVideojuego(){
    int contadorP=0, sumandoP=0;
    float contadorE=0, sumandoE=0;
    
    for(list<Estadistica*>::iterator it=estadisticas.begin(); it!=estadisticas.end(); ++it){
        sumandoE = (*it)->getPuntaje();
        contadorE+= sumandoE;
    }

    if(estadisticas.size() > 0){
        contadorE = contadorE/estadisticas.size();  //calcula promedio
    }
    
    for(list<Partida*>::iterator it=partidas.begin(); it!=partidas.end(); ++it){
        PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(*it);
        if(pi!=NULL){
            sumandoP= pi->darTotalHorasParticipantes();
            contadorP+= sumandoP;
        }else{
            PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(*it);
            if(pm!=NULL){
               sumandoP=pm->darTotalHorasParticipantes();
               contadorP+= sumandoP;
            }
        }
    }
    
    DtJuego* dtJuego = new DtJuego(this->nombre,this->categorias,dev->getNombreEmpresa(),contadorP,contadorE,this->descripcion,this->costo);
    return dtJuego;
}

bool Juego::tengoSuscripcionJugador(Jugador* jugador){
    bool retorno = false;
    for(list<Suscripcion*>::iterator it = sub.begin(); it != sub.end(); ++it){
        if (jugador == (*it)->getJugador()){
            retorno = true;
            return retorno;
        }
    }
    return retorno;
}

bool Juego::tengoCategoria(int catId){
    bool retorno = false;
    for(list<Categoria*>::iterator it = categorias.begin(); it != categorias.end(); ++it){
        if (catId == (*it)->getId()){
            retorno = true;
            return retorno;
        }
    }
    return retorno;
}

void Juego::agregarSuscripcion(Suscripcion* suscripcion){
    this->sub.push_back(suscripcion);
}

void Juego::agregarPartida(Partida* partida){
    this->partidas.push_back(partida);
}

void Juego::agregarEstadistica(Estadistica* estadistica){
    this->estadisticas.push_back(estadistica);
}

void Juego::cancelarSuscripcion(){ 
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuario = sesion->getUsuario();
    Jugador* jugador = dynamic_cast<Jugador*> (usuario);
    list<Suscripcion*>::iterator it = sub.begin(); 
    while(it != sub.end() && (!sub.empty())){
        if (jugador == (*it)->getJugador()){
            this->sub.remove(*it);
            break;
        }
        ++it;
    }
}

Juego::~Juego(){
    this->partidas.clear();
    this->estadisticas.clear();
    this->sub.clear();
}