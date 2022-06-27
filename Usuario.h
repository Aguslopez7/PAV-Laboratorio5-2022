#ifndef USUARIO
#define USUARIO

#include <string>
#include <iostream>
#include "Definiciones.h"
#include "DtFechaHora.h"

using namespace std;

class Usuario{
  private:
    string email;
    string password;
    int tipoUsuario;
  public:
    Usuario();
    Usuario(string email, string password, int tipoUsuario);
    void setEmail(string email);
    void setPassword(string password);
    string getEmail();
    string getPassword();
    int getTipoUsuario();
    virtual ~Usuario() = 0;
};

#endif