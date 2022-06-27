#ifndef IC_VERPARTIDAS
#define IC_VERPARTIDAS

#include <iostream>
#include <list>

#include "DtJuego.h"
#include "Partida.h"

using namespace std;

class ICVerPartidas {
   public:
    virtual list<DtJuego*> listarLosJuegos() = 0;
    virtual bool checkVideojuego(string nombreJuego) = 0;
    virtual list<DtPartida*> verPartidas(string nombreJuego) = 0;
};

#endif