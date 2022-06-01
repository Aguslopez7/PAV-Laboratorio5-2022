#ifndef CATEGORIA
#define CATEGORIA

#include <iostream>

using namespace std;

class Categoria{
    private:
        string descripcion;
        string tipoGenero;
        string tipoPlataforma;
    public:
        Categoria();
        Categoria(string descripcion, string tipoGenero, string tipoPlataforma);
        void setDescripcion(string descripcion);
        void setTipoGenero(string tipoGenero);
        void setTipoPlataforma(string tipoPlataforma);
        string getDescripcion();
        string getTipoGenero();
        string getTipoPlataforma();
        ~Categoria();
};

#endif