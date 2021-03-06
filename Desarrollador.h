#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <iostream>
#include "Definiciones.h"
#include "Usuario.h"

using namespace std;

class Desarrollador : public Usuario{
    private:
        string nombreEmpresa="";
        string email;
        string password;
    public:
        Desarrollador();
        Desarrollador(string email, string password,int tipoUsuario, string nombreEmpresa);
        void setNombreEmpresa(string nombreEempresa);
        string getNombreEmpresa();
        ~Desarrollador();
};

#endif