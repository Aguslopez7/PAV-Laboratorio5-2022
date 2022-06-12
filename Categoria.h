#ifndef CATEGORIA
#define CATEGORIA

#include <iostream>

#include "DtCategoria.h"

using namespace std;

class Categoria{
    private:
        int id;
        string descripcion;
        string tipoGenero;
        string tipoPlataforma;
    public:
        Categoria();
        Categoria(int id, string descripcion, string tipoGenero, string tipoPlataforma);
        void setId(int id);
        void setDescripcion(string descripcion);
        void setTipoGenero(string tipoGenero);
        void setTipoPlataforma(string tipoPlataforma);
        int getId();
        string getDescripcion();
        string getTipoGenero();
        string getTipoPlataforma();
        DtCategoria* getDtCategoria();
        ~Categoria();
};

#endif