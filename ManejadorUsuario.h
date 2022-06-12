#ifndef MANEJADOR_USUARIO
#define MANEJADOR_USUARIO
#include "Usuario.h"
#include <map>
#include <list>
#include <string>
#include <iostream>

using namespace std;

class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        map<string, Usuario*> colUsuarios;
        ManejadorUsuario();
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> listarUsuarios();
        Usuario* buscarUsuario(string email);
        void agregarUsuario(Usuario* usuario);
        bool existeUsuario(string email);
        void eliminarUsuario(string email);
        virtual ~ManejadorUsuario();
};
#endif