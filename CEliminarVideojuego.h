#ifndef C_ELIMINARIDEOJUEGO
#define C_ELIMINARIDEOJUEGO

#include "ICEliminarVideojuego.h"
#include <iostream>
#include <list>

#include "DtJuego.h"

using namespace std;

class CEliminarVideojuego : public ICEliminarVideojuego {
    private:
        string nombreJuego;
    public:
        list<DtJuego*> listarJuegosDev();
        void seleccionarJuego(string nombre);
        void eliminarVideojuego(); 
        void cancelar();
};

#endif