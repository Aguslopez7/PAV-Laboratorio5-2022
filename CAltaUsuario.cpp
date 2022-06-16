#include "CAltaUsuario.h"
#include "ManejadorUsuario.h"

void CAltaUsuario::datosComunes(string email, string password){
    this->email=email;
    this->password=password;
}
void CAltaUsuario::datosEmpresa(string nombreEmpresa){
    this->nombreEmpresa=nombreEmpresa;
}
void CAltaUsuario::datosJugador(string nickname, string descripcion){
    this->nickname=nickname;
    this->descripcion=descripcion;
}
void CAltaUsuario::ingNickname(string nickname){
    this->nickname=nickname;
}
<<<<<<< HEAD
bool CAltaUsuario::checkUser(string data){
=======
bool checkUser(string data){
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
    ManejadorUsuario* mU= ManejadorUsuario::getInstancia();
    return mU->existeUsuario(data);
}
void CAltaUsuario::altaUsuario(){
    if(!(checkUser(this->email))){
<<<<<<< HEAD
        if (this->nombreEmpresa != ""){
=======
        if (this->nombreEmpresa != "") {
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
            Desarrollador* nuevoDev = new Desarrollador(this->email, this->password, this->nombreEmpresa);
            ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
            mU->agregarUsuario(nuevoDev);
        }
        else if(!(checkUser(this->nickname)) && (this->nickname != "")){ 
                Jugador* nuevoJug = new Jugador(this->email, this->password, this->nickname, this->descripcion);
                ManejadorUsuario* mU = ManejadorUsuario::getInstancia();
                mU->agregarUsuario(nuevoJug);
            }else{
                throw invalid_argument("♦ Ese nickname ya existe.");
            }
    }else {
        throw invalid_argument("♦ Ese email ya existe.");
    }
}
void CAltaUsuario::cancelar(){
    //Cancela operacion y se elimina la memoria asociada
}