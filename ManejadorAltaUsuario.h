#ifndef MANEJADOR_ALTAUSUARIO
#define MANEJADOR_ALTAUSUARIO
#include "Usuario.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorAltaUsuario{
    private:
        static ManejadorAltaUsuario* instancia;
        map<string,Usuario*> usuarios;
        ManejadorAltaUsuario();
    public:
        static ManejadorAltaUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        Usuario* buscarUsuario(string);
        void agregarUsuario(Usuario*);
        bool existeUsuario(string);
        void eliminarUsuario(string);
        virtual ~ManejadorAltaUsuario();
};
#endif