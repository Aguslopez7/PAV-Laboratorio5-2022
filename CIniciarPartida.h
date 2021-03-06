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
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"

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
        char tipo;
    public:
        void seleccionarVideojuego(string nombre);
        void datoIndividual(bool continuaPartidaAnterior, int duracion, int tipo);
        void datoMultijugador(bool transmitidaEnVivo, int duracion, int cantJugadores, int tipo);
        void altaPartida();
        void cancelar();
};

#endif