#include "Jugador.h"

Jugador::Jugador(){}

Jugador::Jugador(string email, string password, string nickname, string descripcion) : Usuario(email,password){
    this->nickname=nickname;
    this->descripcion=descripcion;
}

void Jugador:: setNickname(string nickname){
    this->nickname=nickname;
}

void Jugador:: setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

string Jugador:: getNickname(){
    return this->nickname;
}

string Jugador:: getDescripcion(){
    return this->descripcion;
}

/*DtJugador *Jugador:: getDtJugador(){
    DtJugador *dt = new DtJugador(this->edad, this->nickname);
    return dt;
}*/

Jugador::~Jugador(){}

