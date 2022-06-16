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

  public:
    Usuario();
    Usuario(string email, string password);
    void setEmail(string email);
    void setPassword(string password);
    string getEmail();
    string getPassword();
    virtual ~Usuario() = 0;
};

#endif