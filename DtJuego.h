#ifndef DTJUEGO
#define DTJUEGO

#include <iostream>
#include <list>

#include "DtCategoria.h"

using namespace std;

class DtJuego {
  private:
    string nombre;
    list<DtCategoria*> categoria;
    string empresa;
    int totalHorasJuego;      // Calcular total horas juego
    float puntajePromedio;    // Calcular puntaje promedio
    string descripcion;
    int costo;
  public:
    DtJuego();
    DtJuego(string nombre, list<DtCategoria*> categoria, string empresa, int totalHorasJuego, float puntajePromedio, string descripcion, int costo);
    void setNombre(string nombre);
    void setCategoria(list<DtCategoria*> categoria);
    void setEmpresa(string empresa);
    void setTotalHorasJuego(int totalPartidas);
    void setPuntajePromedio (float puntajePromedio);
    void setDescripcion(string descripcion);
    void setCosto(int costo);
    string getNombre();
    list<DtCategoria*> getCategoria();
    string getEmpresa();
    int getTotalHorasJuego();
    float getPuntajePromedio();
    string getDescripcion();
    int getCosto();
    void imprimirVerInfo();
    void imprimirSuscripto();
    ~DtJuego();
};

#endif