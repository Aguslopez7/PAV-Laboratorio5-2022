#ifndef DTCATEGORIA
#define DTCATEGORIA

#include <string>
#include <iostream>

using namespace std;

class DtCategoria {
  private:
    int id;
    string tipoGenero;
    string tipoPlataforma;
  public:
    DtCategoria();
    DtCategoria(int id, string tipoGenero, string tipoPlataforma);
    void setId(int id);
    void setGenero(string tipoGenero);
    void setPlataforma(string tipoPlataforma);
    string getGenero();
    int getId();
    string getPlataforma();
    ~DtCategoria();
};

#endif