#include "Usuario.h"
#include <list>
#include "ManejadorIniciarSesion.h"
using namespace std;

ManejadorIniciarSesion* ManejadorIniciarSesion::instancia = NULL;

ManejadorIniciarSesion::ManejadorIniciarSesion(){}

ManejadorIniciarSesion* ManejadorIniciarSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorIniciarSesion();
    return instancia;
}

list<Usuario*> ManejadorIniciarSesion::getUsuarios(){
    list<Usuario*> lstUsuarios;
    for (map<string,Usuario*>::iterator it=this->Usuarios.begin(); it!=Usuarios.end(); ++it)
        lstUsuarios.push_back(it->second);
    return lstUsuarios;
}

Usuario* ManejadorIniciarSesion::buscarUsuario(string Usuario){
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  return it->second;
}

void ManejadorIniciarSesion::agregarUsuario(Usuario* Usuario){
    Usuarios.insert(std::pair<string,Usuario*>(Usuario->getCi(),Usuario));
}

bool ManejadorIniciarSesion::existeUsuario(string Usuario){ 
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  return (it != this->Usuarios.end());
}

void ManejadorIniciarSesion::eliminarUsuario(string Usuario){
  map<string,Usuario*>::iterator it = this->Usuarios.find(Usuario);
  this->Usuarios.erase(it);
}

ManejadorIniciarSesion::~ManejadorIniciarSesion(){}
