#ifndef IC_ALTAUSUARIO
#define IC_ALTAUSUARIO

#include <iostream> 
using namespace std;

class ICAltaUsuario{
    public:
    virtual void datosComunes(string email, string password) = 0;
    virtual void datosEmpresa(string nombreEmpresa) = 0;
    virtual void datosJugador(string nickname, string descripcion) = 0;
    virtual void ingNickname(string nickname) = 0;
    virtual bool checkUser(string data) = 0;
    virtual void altaUsuario() = 0;
    virtual void cancelar() = 0;
};
#endif