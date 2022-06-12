#include "CIniciarSesion.h"
#include "ManejadorUsuario.h"

bool CIniciarSesion::ingresarDatos(string email, string password) {
    string pass;
    bool login = false;
    bool exist;
    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();  // creo instancia de manejador
    if (exist = mU->existeUsuario(email)) {                   // busco si existe el usuario
        Usuario* u = mU->buscarUsuario(email);                // busco al usuario
        pass = u->getPassword();
        if (pass == password) {
            Sesion* sesion = Sesion::getInstancia();
            sesion->setUsuario(u);
            login = true;
        }
    } else
       login = false;
    return login;  

}

