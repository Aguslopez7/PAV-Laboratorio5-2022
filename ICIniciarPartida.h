#ifndef IC_INICIARPARTIDA
#define IC_INICIARPARTIDA

#include <iostream> 
#include <list>

using namespace std;

class ICIniciarPartida{
    public:
        virtual void seleccionarVideojuego(string nombre) = 0;
        virtual void datoIndividual(bool continuaPartidaAnterior, int duracion, int tipo) = 0;
        virtual void datoMultijugador(bool trasmitidaEnVivo, int duracion, int cantJugadores, int tipo) = 0;
        virtual void altaPartida() = 0;
        virtual void cancelar() = 0;
};
#endif