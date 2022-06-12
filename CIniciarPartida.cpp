#include "CIniciarPartida.h"
#include "ManejadorPartida.h"
#include "Sesion.h"
#include "Usuario.h"

/*list<string> CIniciarPartida::listarVideoJuegosSuscripcionActiva(){
    Sesion* s = Sesion::getInstancia();
    Usuario* usuario = s->getUsuario();  
    Jugador* jugador = dynamic_cast<Jugador*>(usuario);
    list<string> videoJuegosSuscripcionActiva = jugador->asignaturas();
    this->jugador= jugador;
    return videoJuegosSuscripcionActiva;
}*/

/*bool CIniciarPartida::tieneSuscripcionActiva(string nickname){ 
    this->nickname=nickname;
    //return   
}*/

void CIniciarPartida::seleccionarVideojuego(string nombre){
    /*bool mon=jugador->tieneSuscripcionActiva(inicioClase->getCodigo());//ver
    this->inicioClase=inicioClase;
    return mon;*/
}

void CIniciarPartida::datoIndividual(bool continuaPartidaAnterior, int duracion){
    this->continuaPartidaAnterior=continuaPartidaAnterior;
    this->duracion=duracion;
}

void CIniciarPartida::datoMultijugador(bool transmitidaEnVivo, int duracion, int cantJugadores){
    this->transmitidaEnVivo=transmitidaEnVivo;
    this->duracion=duracion;
    this->cantJugadores=cantJugadores;
}

void CIniciarPartida::altaPartida(){
    
}