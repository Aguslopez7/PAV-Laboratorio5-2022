#include "Desarrollador.h"

Desarrollador::Desarrollador(){}

Desarrollador::Desarrollador(string email, string password,int tipoUsuario, string nombreEmpresa) : Usuario(email,password,tipoUsuario){
    this->nombreEmpresa=nombreEmpresa;
}

void Desarrollador:: setNombreEmpresa(string nombreEmpresa){
    this->nombreEmpresa=nombreEmpresa;
}

string Desarrollador:: getNombreEmpresa(){
    return this->nombreEmpresa;
}

/*DtDesarrollador *Desarrollador:: getDtDesarrollador(){
    DtDesarrollador *dt = new DtDesarrollador(this->edad, this->nickname);
    return dt;
}*/

Desarrollador::~Desarrollador(){}