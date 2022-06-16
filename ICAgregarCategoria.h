#ifndef IC_AGREGARCATEGORIA
#define IC_AGREGARCATEGORIA

#include <iostream>
#include <list>
#include "DtCategoria.h"

using namespace std;

class ICAgregarCategoria {
   public:
<<<<<<< HEAD
    virtual list<DtCategoria*> listarDtCategorias() = 0;
=======
    virtual list<DtCategoria*> listCategorias() = 0;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
    virtual void solictarDatos(int id, string genero, string plataforma) = 0;
    virtual void confirmarCategoria() = 0;
    virtual void cancelar() = 0;
};

#endif