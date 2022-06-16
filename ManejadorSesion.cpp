#include "Usuario.h"
#include <list>
#include "ManejadorSesion.h"
#include "Usuario.h"
using namespace std;

ManejadorSesion* ManejadorSesion::instancia = NULL;

ManejadorSesion::ManejadorSesion(){}

ManejadorSesion* ManejadorSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorSesion();
    return instancia;
}

list<Usuario*> ManejadorSesion::getUsuarios(){
    list<Usuario*> lstusuarios;
    for (map<string,Usuario*>::iterator it=this->usuarios.begin(); it!=usuarios.end(); ++it)
        lstusuarios.push_back(it->second);
    return lstusuarios;
}

Usuario* ManejadorSesion::buscarUsuario(string usuarios){
  map<string,Usuario*>::iterator it = this->usuarios.find(usuarios);
  return it->second;
}

void ManejadorSesion::agregarUsuario(Usuario* usuarios){
    this->usuarios.insert(std::pair<string,Usuario*>(usuarios->getEmail(),usuarios)); //email identifica user
}

bool ManejadorSesion::existeUsuario(string usuarios){ 
  map<string,Usuario*>::iterator it = this->usuarios.find(usuarios);
  return (it != this->usuarios.end());
}

void ManejadorSesion::eliminarUsuario(string usuarios){
  map<string,Usuario*>::iterator it = this->usuarios.find(usuarios);
  this->usuarios.erase(it);
}

ManejadorSesion::~ManejadorSesion(){}
