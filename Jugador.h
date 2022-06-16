#ifndef JUGADOR
#define JUGADOR

#include <iostream>
#include "Definiciones.h"
#include "Usuario.h"
//#include "DtJugador.h"

using namespace std;

class Jugador : public Usuario{
    private:
        string nickname, descripcion;
    public:
        Jugador();
        Jugador(string email, string password, string nickname, string descripcion);
        void setNickname(string nickname);
        void setDescripcion(string descripcion);
        string getNickname();
        string getDescripcion();
        /*DtJugador *getDtJugador();*/
        ~Jugador();
};

#endif