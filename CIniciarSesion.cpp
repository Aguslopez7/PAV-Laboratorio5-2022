#include "CIniciarSesion.h"
#include "ManejadorUsuario.h"
<<<<<<< HEAD
#include "Sesion.h"
#include "Desarrollador.h"
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

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
<<<<<<< HEAD
}

bool CIniciarSesion::usuarioConectado() {
	bool owo = false;
    Sesion* sesion = Sesion::getInstancia();
    Usuario* usuario = sesion->getUsuario();
	Desarrollador* dev = dynamic_cast<Desarrollador*> (usuario);
	if (dev != NULL){
		owo = true;
		return owo;
	}
	else
	{
		owo = false;
		return owo;
	}
}

string CIniciarSesion::getEmail(){
	Sesion* sesi = Sesion::getInstancia();
	Usuario* u = sesi->getUsuario();
	return this->email;
}
=======

}

>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
