#include "DtJuego.h"
#include "Definiciones.h"

DtJuego::DtJuego(){}

DtJuego::DtJuego(string nombre, list<Categoria*> categoria, string empresa,  int totalHorasJuego, float puntajePromedio, string descripcion, int costo)
{
    this->nombre=nombre;
    this->categoria=categoria;
    this->empresa=empresa;
    this->totalHorasJuego=totalHorasJuego;
    this->puntajePromedio=puntajePromedio;
    this->descripcion=descripcion;
    this->costo=costo;
}

void DtJuego::setNombre(string nombre){
    this->nombre=nombre;
}

void DtJuego::setCategoria(list<Categoria*> categoria){
    this->categoria=categoria;
}

void DtJuego::setEmpresa(string empresa){
    this->empresa=empresa;
}

void DtJuego::setPuntajePromedio (float puntajePromedio){
    this->puntajePromedio=puntajePromedio;

}

void DtJuego::setTotalHorasJuego(int totalHorasJuego){
    this->totalHorasJuego=totalHorasJuego;

}

void DtJuego::setDescripcion(string descripcion){
    this->descripcion=descripcion;
}

void DtJuego::setCosto(int totalHorasJuego){
    this->costo=costo;

}

list<Categoria*> DtJuego::getCategoria(){
    return this->categoria;
}

string DtJuego::getEmpresa(){
    return this->empresa;
}

float DtJuego::getPuntajePromedio(){
    return this->puntajePromedio;
}

int DtJuego::getTotalHorasJuego(){
    return this->totalHorasJuego;
}

string DtJuego::getDescripcion(){
    return this->descripcion;
}

int DtJuego::getCosto(){
    return this->costo;
}
string DtJuego::getNombre(){
    return this->nombre;
}

void DtJuego::imprimirInfo(){
    cout << "\n" << longTab << COLOR_LG << " ❯ Nombre: " << this->nombre << endl;
    cout << longTab << " ❯ Descripcion: " << this->descripcion << endl;
    cout << longTab << " ❯ Costo: $" << this->costo << endl;
    cout << longTab << " ❯ Categorias:" << endl;
    for(list<Categoria*>::iterator it = this->categoria.begin(); it != this->categoria.end(); ++it){
        cout << longTab << "   " << "#id: " << (*it)->getId() << " -> " << (*it)->getTipoGenero() << "/" << (*it)->getTipoPlataforma() << endl;
    }
    cout << longTab << " ❯ Empresa: " << this->empresa << endl;
    cout << longTab << " ❯ Puntaje promedio: " << this->puntajePromedio << endl;
    cout << longTab << " ❯ Total horas jugadas: " << this->totalHorasJuego << COLOR_RESET << endl;
}

void DtJuego::imprimirNombreCosto(){
    cout << longTab << COLOR_LG << " ❯ Nombre: " << this->nombre << endl;
    cout << longTab << " ❯ Costo: $" << this->costo << COLOR_RESET << endl;
}

void DtJuego::imprimirNombre(){
    cout << longTab << COLOR_LG << "┌────────────────────┐" << endl;
    cout << longTab << "│ ❯ Nombre: " << this->nombre << endl;
    cout << longTab << "└────────────────────┘" << COLOR_RESET << endl;
}

void DtJuego::imprimirNombreDesc(){
    cout << longTab << COLOR_LG << " ❯ Nombre: " << this->nombre << endl;
    cout << longTab << " ❯ Descrpcion: " << this->descripcion << COLOR_RESET << endl;
}

void DtJuego::imprimirNomPuntajeHorasP(){
    cout << longTab << " " << COLOR_LG << "❯ Puntaje promedio: " << this->puntajePromedio << endl;
    cout << longTab << COLOR_SB << " ❯ Nombre: " << this->nombre << endl;
    cout << longTab << " ❯ Descripcion: " << this->descripcion << endl;
    cout << longTab << " ❯ Total horas jugadas: " << this->totalHorasJuego << COLOR_RESET << endl;;
}

void DtJuego::imprimirNomPuntajeHorasH(){
    cout << longTab << " " << COLOR_LG << "❯ Total horas jugadas: " << this->totalHorasJuego << endl;
    cout << longTab << COLOR_SB << " ❯ Nombre: " << this->nombre << endl;
    cout << longTab << " ❯ Descripcion: " << this->descripcion << endl;
    cout << longTab << " ❯ Puntaje promedio: " << this->puntajePromedio << COLOR_RESET << endl;
}

DtJuego::~DtJuego(){}