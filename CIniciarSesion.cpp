#include "CIniciarSesion.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"
#include "Desarrollador.h"

bool CIniciarSesion::ingresarDatos(string email, string password) {
    string pass;
    bool login = false;
    bool exist;
    ManejadorUsuario* mU = ManejadorUsuario::getInstancia();  // creo instancia de manejador
    exist = mU->existeUsuario(email);
    if (exist) {                                              // busco si existe el usuario
        Usuario* u = mU->buscarUsuario(email);                // busco al usuario
        pass = u->getPassword();
        if (pass == password) {
            Sesion* sesion = Sesion::getInstancia();
            sesion->setUsuario(u);
            login = true;
        }
    } else{
       login = false;
    }
    return login;    
}

bool CIniciarSesion::signUp(){
    bool retorno = true;
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuario = sesion->getUsuario();
    if (usuario == NULL)    
    {
        retorno = false;
        return retorno;
    }else{
        return retorno;
    }
}

bool CIniciarSesion::usuarioConectado() {
	bool owo = false;
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuario = sesion->getUsuario();
    int tipo = usuario->getTipoUsuario();
    if (tipo == 1){
        owo = true;
    }else if(tipo == 0){
        owo = false;
    }
    return owo;
}

string CIniciarSesion::getEmail(){
	Sesion* sesi = Sesion::getInstancia();
	Usuario* u = sesi->getUsuario();
    string email = u->getEmail();
	return email;
}
