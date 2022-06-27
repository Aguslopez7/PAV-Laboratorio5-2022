#ifndef IC_ASIGNARPUNTAJE
#define IC_ASIGNARPUNTAJE

#include <iostream> 

using namespace std;

class ICAsignarPuntaje{
    public:
    virtual void asignarPuntaje(string nombreJuego, int puntaje) = 0;
};
#endif