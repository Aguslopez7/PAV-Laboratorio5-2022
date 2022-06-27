#ifndef IC_BUSCARPORCATEGORIA
#define IC_BUSCARPORCATEGORIA

#include <iostream> 

#include "DtJuego.h"
<<<<<<< HEAD
#include "DtCategoria.h"
=======
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca

using namespace std;

class ICBuscarPorCategoria{
    public:
<<<<<<< HEAD
    virtual bool existeCategoria(int idCat) = 0;
    virtual Categoria* dameCategoria(int idCat) = 0;
=======
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    virtual list<DtJuego*> buscarPorCategoria(int idCat) = 0;
};
#endif