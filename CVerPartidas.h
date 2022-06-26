#ifndef C_VERPARTIDAS
#define C_VERPARTIDAS

#include <iostream>
#include <list>

#include "DtJuego.h"
#include "DtPartida.h"
#include "ICVerPartidas.h"

using namespace std;

class CVerPartidas : public ICVerPartidas {
    private:
        string nombreJuego;
    public:
        list<DtJuego*> listarLosJuegos(); 
        bool checkVideojuego(string nombreJuego);
        list<DtPartida*> verPartidas(string nombreJuego);
};

#endif