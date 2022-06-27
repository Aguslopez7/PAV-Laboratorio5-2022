#ifndef MANEJADOR_SESION
#define MANEJADOR_SESION
#include "Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorSesion{
    private:
        static ManejadorSesion* instancia;
        map<string,Usuario*> usuarios;   
        ManejadorSesion();
    public:
        static ManejadorSesion* getInstancia();
        list<Usuario*> getUsuarios();
        Usuario* buscarUsuario(string);
        void agregarUsuario(Usuario*);
        bool existeUsuario(string);
        void eliminarUsuario(string);
        virtual ~ManejadorSesion();
};
#endif