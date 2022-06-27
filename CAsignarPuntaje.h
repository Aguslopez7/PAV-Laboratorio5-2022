#ifndef C_ASIGNARPUNTAJE
#define C_ASIGNARPUNTAJE

#include <iostream>
#include <list>
#include "ICAsignarPuntaje.h"

using namespace std;

class CAsignarPuntaje : public ICAsignarPuntaje {
    private:
        string nombreJuego;
        int puntaje;
    public:
        void asignarPuntaje(string nombreJuego, int puntaje);
};

#endif