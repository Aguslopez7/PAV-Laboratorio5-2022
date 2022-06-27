#include "CAltaUsuario.h"
#include "ManejadorUsuario.h"

void CAltaUsuario::datosComunes(string email, string password)
{
    this->email = email;
    this->password = password;
}

void CAltaUsuario::datosEmpresa(string nombreEmpresa)
{
    this->nombreEmpresa = nombreEmpresa;
}

void CAltaUsuario::datosJugador(string nickname, string descripcion)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
}

void CAltaUsuario::ingNickname(string nickname)
{
    this->nickname = nickname;
}

bool CAltaUsuario::checkUser(string data)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    return mU->existeUsuario(data);
}

bool CAltaUsuario::hayUsuarios()
{
    int cont = 0;
    bool retorno = true;
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    list<Usuario *> lista = mU->listarUsuarios();
    for (list<Usuario *>::iterator it = lista.begin(); it != lista.end(); it++)
    {
        cont++;
    }
    if (cont >= 1){
            return retorno;
    }
    else
    {
        retorno = false;
        return retorno;
    }
}

void CAltaUsuario::altaUsuario()
{
<<<<<<< HEAD
    if (!(this->nombreEmpresa.empty())){
=======
    if (!(this->nombreEmpresa.empty()))
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        int tipoUsuario = 1;
        Desarrollador *nuevoDev = new Desarrollador(this->email, this->password, tipoUsuario, this->nombreEmpresa);
        ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
        mU->agregarUsuario(nuevoDev);
<<<<<<< HEAD
    }else if (!(checkUser(this->nickname)) && (!(this->nickname.empty()))){
=======
    }
    else if (!(checkUser(this->nickname)) && (!(this->nickname.empty())))
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        int tipoUsuario = 0;
        Jugador *nuevoJug = new Jugador(this->email, this->password, tipoUsuario, this->nickname, this->descripcion);
        ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
        mU->agregarUsuario(nuevoJug);
<<<<<<< HEAD
    }else{
        throw invalid_argument("│ 🔔 Ya Existe ese Nickname! │");
=======
    }
    else
    {
        throw invalid_argument("♦ Ese nickname ya existe.");
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    }
}

void CAltaUsuario::cancelar()
{
    // Cancela operacion y se elimina la memoria asociada
}