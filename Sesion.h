#ifndef SESION
#define SESION
#include <iostream>
#include "Usuario.h"

using namespace std;

class Sesion{
    private:
<<<<<<< HEAD
        Usuario* usuario;
=======
        Usuario* usuario = NULL;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        static Sesion* instancia;
        Sesion();
    public:
		static Sesion* getInstancia();
        void setUsuario(Usuario* usuario);
        Usuario* getUsuario();
        ~Sesion();
};
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
