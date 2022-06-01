#include "Usuario.h"

Usuario::Usuario(){}

Usuario::Usuario(string email, string password){
    this->email=email;
    this->password=password;
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

/*DtUsuario *Usuario:: getDtUsuario(){
    DtUsuario *dt = new DtUsuario(this->edad, this->nickname);
    return dt;
}*/

Usuario::~Usuario(){}