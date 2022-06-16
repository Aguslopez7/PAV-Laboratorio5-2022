#include "CIniciarPartida.h"
<<<<<<< HEAD
=======
#include "ManejadorPartida.h"
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
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

<<<<<<< HEAD
bool CIniciarPartida::tieneSuscripcionActiva(string nickname){ /*
    this->nickname=nickname;
    //return   */
    return true;
}
=======
/*bool CIniciarPartida::tieneSuscripcionActiva(string nickname){ 
    this->nickname=nickname;
    //return   
}*/
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

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
    
<<<<<<< HEAD
}

void CIniciarPartida::cancelar(){
    //se libera la memoria
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
}