#include "Usuario.h"
#include <list>
#include "ManejadorUsuario.h"
using namespace std;

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

list<Usuario*> ManejadorUsuario::listarUsuarios(){
    list<Usuario*> listUsuarios;
    for (map<string,Usuario*>::iterator it=this->colUsuarios.begin(); it!=colUsuarios.end(); ++it)
        listUsuarios.push_back(it->second);
    return listUsuarios;
}

Usuario* ManejadorUsuario::buscarUsuario(string email){
  map<string, Usuario*>::iterator it = this->colUsuarios.find(email);
  return it->second;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario){
    this->colUsuarios.insert(pair<string, Usuario*>(usuario->getEmail(),usuario));
}

bool ManejadorUsuario::existeUsuario(string email){ 
  map<string,Usuario*>::iterator it = this->colUsuarios.find(email);
    return (it != this->colUsuarios.end());
}

void ManejadorUsuario::eliminarUsuario(string email){
  map<string,Usuario*>::iterator it = this->colUsuarios.find(email);
  this->colUsuarios.erase(it);
}

ManejadorUsuario::~ManejadorUsuario(){}
