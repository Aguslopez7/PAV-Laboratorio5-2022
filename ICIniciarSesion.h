#ifndef IC_INICIARSESION
#define IC_INICIARSESION

#include <iostream> 

using namespace std;

class ICIniciarSesion{
    public:
    virtual bool ingresarDatos(string email, string password) = 0;
    virtual bool usuarioConectado() = 0;
    virtual string getEmail()=0;
};
#endif