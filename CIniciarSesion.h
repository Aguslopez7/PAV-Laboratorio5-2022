#ifndef C_INICIARSESION
#define C_INICIARSESION

#include <iostream> 

<<<<<<< HEAD
#include "Sesion.h"
#include "ICIniciarSesion.h"
#include "Usuario.h"
=======
#include"Sesion.h"
#include "ICIniciarSesion.h"
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

using namespace std;

class CIniciarSesion : public ICIniciarSesion{
    private:
<<<<<<< HEAD
        Usuario *usuario;
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        string email;
        string password;
    public:
        bool ingresarDatos(string email, string password);
<<<<<<< HEAD
        bool usuarioConectado();
        string getEmail();
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
};

#endif