#ifndef MANEJADOR_INICICARSESION
#define MANEJADOR_INICICARSESION
#include "Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorIniciarSesion{
    private:
        static ManejadorIniciarSesion* instancia;
        map<string,Usuario*> usuarios;   
        ManejadorIniciarSesion();
    public:
        static ManejadorIniciarSesion* getInstancia();
        list<Usuario*> getUsuarios();
        Usuario* buscarUsuario(string);
        void agregarUsuario(Usuario*);
        bool existeUsuario(string);
        void eliminarUsuario(string);
        virtual ~ManejadorIniciarSesion();
};
#endif