#ifndef C_RANKINGVIDEOJUEGO
#define C_RANKINGVIDEOJUEGO

#include <iostream>

#include "DtJuego.h"
#include "ICRankingVideojuego.h"

using namespace std;

class CRankingVideojuego : public ICRankingVideojuego {
    public:
        static bool compararPorPuntaje(DtJuego* juego1, DtJuego* juego2);
        static bool compararPorDuracion(DtJuego* juego1, DtJuego* juego2);
        list<DtJuego*> listarPorPuntaje();
        list<DtJuego*> listarPorDuracion();
};

#endif