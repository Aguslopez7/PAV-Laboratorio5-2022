#ifndef IC_INICIARPARTIDA
#define IC_INICIARPARTIDA

#include <iostream> 
<<<<<<< HEAD
#include <list>

=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
using namespace std;

class ICIniciarPartida{
    public:
<<<<<<< HEAD
        //virtual list <string> listarVideoJuegosSuscripcionActiva() = 0;
=======
        virtual list <string> listarVideoJuegosSuscripcionActiva() = 0;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        virtual bool tieneSuscripcionActiva(string nickname)= 0; 
        virtual void seleccionarVideojuego(string nombre)= 0;
        virtual void datoIndividual(bool continuaPartidaAnterior, int duracion)= 0;
        virtual void datoMultijugador(bool trasmitidaEnVivo, int duracion, int cantJugadores)= 0;
        virtual void altaPartida()= 0;
        virtual void cancelar()= 0;
};
#endif