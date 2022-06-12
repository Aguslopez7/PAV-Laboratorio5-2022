#ifndef C_INICIARSESION
#define C_INICIARSESION

#include <iostream> 

#include"Sesion.h"
#include "ICIniciarSesion.h"

using namespace std;

class CIniciarSesion : public ICIniciarSesion{
    private:
        string email;
        string password;
    public:
        bool ingresarDatos(string email, string password);
};

#endif