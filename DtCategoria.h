#ifndef DTCATEGORIA
#define DTCATEGORIA

#include <string>
#include <iostream>

using namespace std;

class DtCategoria {
  private:
    string tipoGenero;
    string tipoPlataforma;
  public:
    DtCategoria();
    DtCategoria(string tipoGenero, string tipoPlataforma);
    void setGenero(string tipoGenero);
    void setPlataforma(string tipoPlataforma);
    string getGenero();
    string getPlataforma();
    ~DtCategoria();
};

#endif