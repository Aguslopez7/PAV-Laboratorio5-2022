#ifndef IC_INICIARPARTIDA
#define IC_INICIARPARTIDA

#include <iostream> 
using namespace std;

class ICIniciarPartida{
    public:
        virtual list <string> listarVideoJuegosSuscripcionActiva() = 0;
        virtual bool tieneSuscripcionActiva(string nickname)= 0; 
        virtual void seleccionarVideojuego(string nombre)= 0;
        virtual void datoIndividual(bool continuaPartidaAnterior, int duracion)= 0;
        virtual void datoMultijugador(bool trasmitidaEnVivo, int duracion, int cantJugadores)= 0;
        virtual void altaPartida()= 0;
        virtual void cancelar()= 0;
};
#endif