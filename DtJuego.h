#ifndef DTJUEGO
#define DTJUEGO

#include <iostream>

#include "DtCategoria.h"

using namespace std;

class DtJuego {
  private:
    string nombre;
    DtCategoria* categoria;
    string empresa;
    int totalHorasJuego;      // Calcular total horas juego
    float puntajePromedio;    // Calcular puntaje promedio
    string descripcion;
    int costo;
  public:
    DtJuego();
    DtJuego(string nombre, DtCategoria* categoria, string empresa, int totalHorasJuego, float puntajePromedio, string descripcion, int costo);
    void setNombre(string nombre);
    void setCategoria(DtCategoria* categoria);
    void setEmpresa(string empresa);
    void setTotalHorasJuego(int totalPartidas);
    void setPuntajePromedio (float puntajePromedio);
    void setDescripcion(string descripcion);
    void setCosto(int costo);
    string getNombre();
    DtCategoria* getCategoria();
    string getEmpresa();
    int getTotalHorasJuego();
    float getPuntajePromedio();
    string getDescripcion();
    int getCosto();
    ~DtJuego();
};

#endif