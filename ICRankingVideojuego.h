#ifndef IC_RANKINGVIDEOJUEGO
#define IC_RANKINGVIDEOJUEGO

#include <iostream> 
#include <list>

#include "DtJuego.h"

using namespace std;

class ICRankingVideojuego{
    public:
        static bool compararPorPuntaje(DtJuego* juego1,DtJuego* juego2);
        static bool compararPorDuracion(DtJuego* juego1,DtJuego* juego2);
        virtual list<DtJuego*> listarPorPuntaje() = 0;
        virtual list<DtJuego*> listarPorDuracion() = 0;
};
#endif