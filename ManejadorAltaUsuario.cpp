#include "Usuario.h"
#include <list>
#include "ManejadorAltaUsuario.h"
using namespace std;

ManejadorAltaUsuario* ManejadorAltaUsuario::instancia = NULL;

ManejadorAltaUsuario::ManejadorAltaUsuario(){}

ManejadorAltaUsuario* ManejadorAltaUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorAltaUsuario();
    return instancia;
}

list<Usuario*> ManejadorAltaUsuario::getUsuarios(){
    list<Usuario*> lstUsuarios;
    for (map<string,Usuario*>::iterator it=this->Usuarios.begin(); it!=Usuarios.end(); ++it)
        lstUsuarios.push_back(it->second);
    return lstUsuarios;
}

Usuario* ManejadorAltaUsuario::buscarUsuario(string Usuario){
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  return it->second;
}

void ManejadorAltaUsuario::agregarUsuario(Usuario* Usuario){
    Usuarios.insert(std::pair<string,Usuario*>(Usuario->getCi(),Usuario));
}

bool ManejadorAltaUsuario::existeUsuario(string Usuario){ 
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  return (it != this->Usuarios.end());
}

void ManejadorAltaUsuario::eliminarUsuario(string Usuario){
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  this->Usuarios.erase(it);
}

ManejadorAltaUsuario::~ManejadorAltaUsuario(){}
