#ifndef C_AGREGARCATEGORIA
#define C_AGREGARCATEGORIA

#include <iostream>
#include <list>
#include "Categoria.h"
#include "DtCategoria.h"
#include "ICAgregarCategoria.h"

using namespace std;

class CAgregarCategoria : public ICAgregarCategoria {
    private:
        int id;
        string descripcion;
        string genero;
        string plataforma;
    public:
        list<DtCategoria*> listarDtCategorias();
        bool hayCategorias();
        void solictarDatos( string descripcion, string genero, string plataforma);
        void confirmarCategoria();
        DtCategoria* buscarCat(int id);
        void cancelar();
};

#endif