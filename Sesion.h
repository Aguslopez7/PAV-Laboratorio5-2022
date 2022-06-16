#ifndef SESION
#define SESION
#include <iostream>
#include "Usuario.h"

using namespace std;

class Sesion{
    private:
        Usuario* usuario;
        static Sesion* instancia;
        Sesion();
    public:
		static Sesion* getInstancia();
        void setUsuario(Usuario* usuario);
        Usuario* getUsuario();
        ~Sesion();
};
#endif