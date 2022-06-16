#ifndef C_AGREGARCATEGORIA
#define C_AGREGARCATEGORIA

#include <iostream>
<<<<<<< HEAD
#include <list>
=======

>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
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
<<<<<<< HEAD
        list<DtCategoria*> listarDtCategorias();
=======
        list<DtCategoria*> listCategorias();
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        void solictarDatos(int id, string genero, string plataforma);
        void confirmarCategoria();
        void cancelar();
};

#endif