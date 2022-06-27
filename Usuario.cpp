#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string email, string password, int tipoUsuario){
    this->email=email;
    this->password=password;
    this->tipoUsuario=tipoUsuario;
}

void Usuario:: setEmail(string email){
    this->email=email;
}

void Usuario:: setPassword(string password){
    this->password=password;
}
string Usuario:: getPassword(){
    return this->password;
}

string Usuario:: getEmail(){
    return this->email;
}

int Usuario::getTipoUsuario(){
    return this->tipoUsuario;
}

/*DtUsuario *Usuario:: getDtUsuario(){
    DtUsuario *dt = new DtUsuario(this->edad, this->nickname);
    return dt;
}*/

Usuario::~Usuario(){}