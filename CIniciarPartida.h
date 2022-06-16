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
        //list<string> listarVideoJuegosSuscripcionActiva();
        bool tieneSuscripcionActiva(string nickname);
        void seleccionarVideojuego(string nombre);
        void datoIndividual(bool continuaPartidaAnterior, int duracion);
        void datoMultijugador(bool transmitidaEnVivo, int duracion, int cantJugadores);
        void altaPartida();
        void cancelar();
};

#endif