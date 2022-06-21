#ifndef C_INICIARSESION
#define C_INICIARSESION

#include <iostream> 

#include "Sesion.h"
#include "ICIniciarSesion.h"
#include "Usuario.h"

using namespace std;

class CIniciarSesion : public ICIniciarSesion{
    private:
        Usuario *usuario;
        string email;
        string password;
    public:
        bool ingresarDatos(string email, string password);
        bool signUp();
        bool usuarioConectado();
        string getEmail();
};

#endif