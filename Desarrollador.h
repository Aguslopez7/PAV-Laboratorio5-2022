#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <iostream>
#include "Definiciones.h"
#include "Usuario.h"

using namespace std;
class Desarrollador : public Usuario{
    private:
        string nombreEmpresa;
    public:
        Desarrollador();
        Desarrollador(string email, string password, string nombreEmpresa);
        void setNombreEmpresa(string nombreEempresa);
        string getNombreEmpresa();
        /*DtJugador *getDtJugador();*/
        ~Desarrollador();
};

#endif