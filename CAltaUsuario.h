#ifndef C_ALTAUSUARIO
#define C_ALTAUSUARIO

#include <iostream>

#include "Usuario.h"
#include "Desarrollador.h"
#include "Jugador.h"
#include "ICAltaUsuario.h" 

using namespace std;

class CAltaUsuario : public ICAltaUsuario{
    private:
        string email;
        string password;
        string nombreEmpresa;
        string nickname;
        string descripcion;
    public:
        void datosComunes(string email, string password);
        void datosEmpresa(string nomobreEmpresa);
        void datosJugador(string nickname, string descripcion);
        void ingNickname(string nickname);
        bool checkUser(string data);
        void altaUsuario();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
        void cancelar();
};

#endif