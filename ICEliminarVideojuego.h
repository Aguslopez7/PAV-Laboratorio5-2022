#ifndef IC_ELIMINARIDEOJUEGO
#define IC_ELIMINARIDEOJUEGO

#include <iostream>
#include <list> 

using namespace std;

class ICEliminarVideojuego {
    public:
        virtual list<DtJuego*> listarJuegosDev() = 0;
        virtual void seleccionarJuego(string nombre) = 0;
        virtual void eliminarVideojuego() = 0; 
        virtual void cancelar() = 0;
};

#endif