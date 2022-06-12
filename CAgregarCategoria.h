#ifndef C_AGREGARCATEGORIA
#define C_AGREGARCATEGORIA

#include <iostream>

#include "Categoria.h"
#include "DtCategoria.h"
#include "ICAgregarCategoria.h"

using namespace std;

class CAgregarCategoria : public ICAgregarCategoria {
    private:
        int id;
        string genero;
        string plataforma;
    public:
        list<DtCategoria*> listCategorias();
        void solictarDatos(int id, string genero, string plataforma);
        void confirmarCategoria();
        void cancelar();
};

#endif