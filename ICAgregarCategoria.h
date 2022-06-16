#ifndef IC_AGREGARCATEGORIA
#define IC_AGREGARCATEGORIA

#include <iostream>
#include <list>
#include "DtCategoria.h"

using namespace std;

class ICAgregarCategoria {
   public:
    virtual list<DtCategoria*> listarDtCategorias() = 0;
    virtual void solictarDatos(int id, string genero, string plataforma) = 0;
    virtual void confirmarCategoria() = 0;
    virtual void cancelar() = 0;
};

#endif