#ifndef C_INICIARPARTIDA
#define C_INICIARPARTIDA

#include <iostream>
#include <list>
#include <string>

#include "ICIniciarPartida.h"
#include "Juego.h"
#include "Jugador.h"
#include "Partida.h"
#include "Usuario.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"

using namespace std;

class CIniciarPartida : public ICIniciarPartida {
    private:
        Jugador* jugador;
        Juego* juego;
        string nickname;
        string nombre;
        bool continuaPartidaAnterior;
        bool transmitidaEnVivo;
        int duracion;
        int cantJugadores;
        list<Usuario*> suscritos;
    public:
<<<<<<< HEAD
        //list<string> listarVideoJuegosSuscripcionActiva();
=======
        list<string> listarVideoJuegosSuscripcionActiva();
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        bool tieneSuscripcionActiva(string nickname);
        void seleccionarVideojuego(string nombre);
        void datoIndividual(bool continuaPartidaAnterior, int duracion);
        void datoMultijugador(bool transmitidaEnVivo, int duracion, int cantJugadores);
        void altaPartida();
        void cancelar();
};

#endif