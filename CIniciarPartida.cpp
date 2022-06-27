#include <ctime>


#include "ManejadorJuego.h"
#include "CIniciarPartida.h"
#include "Sesion.h"
#include "Usuario.h"

void CIniciarPartida::seleccionarVideojuego(string nombre){
    this->nombre=nombre;
}

void CIniciarPartida::datoIndividual(bool continuaPartidaAnterior, int duracion, int tipo){
    this->continuaPartidaAnterior=continuaPartidaAnterior;
    this->duracion=duracion;
    this->tipo=tipo;
}

void CIniciarPartida::datoMultijugador(bool transmitidaEnVivo, int duracion, int cantJugadores, int tipo){
    this->transmitidaEnVivo=transmitidaEnVivo;
    this->duracion=duracion;
    this->cantJugadores=cantJugadores;
    this->tipo=tipo;
}

void CIniciarPartida::altaPartida(){
    Sesion* sesion = Sesion::getInstancia();
    Usuario* u = sesion->getUsuario();
    Jugador* jug = dynamic_cast<Jugador*> (u);
    ManejadorJuego* manJue = ManejadorJuego::getInstancia();
    Juego* juego = manJue->getJuego(this->nombre);
    list<Partida*> listaPartida = juego->getPartidas();
    if(this->tipo == 2){
        time_t t = time(0);
        tm *now = localtime(&t);                //paso fecha del sistema
        DtFechaHora* fechaHora = new DtFechaHora(now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900), now->tm_hour, now->tm_min);
        int tam = listaPartida.size();
        int id = tam + 1;
        PartidaMultijugador* partMulti = new PartidaMultijugador(id,fechaHora, this->duracion, jug, this->transmitidaEnVivo, this->cantJugadores);
        juego->agregarPartida(partMulti);
    }else if (this->tipo == 1){
        time_t t = time(0);
        tm *now = localtime(&t);                //paso fecha del sistema
        DtFechaHora* fechaHora = new DtFechaHora(now->tm_mday, (now->tm_mon + 1), (now->tm_year + 1900), now->tm_hour, now->tm_min);
        int tam = listaPartida.size();
        int id = tam + 1;
        PartidaIndividual* partIndi = new PartidaIndividual(id,fechaHora, this->duracion, jug, this->continuaPartidaAnterior);
        juego->agregarPartida(partIndi);
    }
}

void CIniciarPartida::cancelar(){
    //se libera la memoria
}