#ifndef C_BUSCARPORCATEGORIA
#define C_BUSCARPORCATEGORIA

#include <iostream>
#include <list>

#include "ICBuscarPorCategoria.h"
#include "DtJuego.h"
<<<<<<< HEAD
#include "DtCategoria.h"
=======
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca

using namespace std;

class CBuscarPorCategoria : public ICBuscarPorCategoria {
    private:
        int catId;
    public:
<<<<<<< HEAD
        bool existeCategoria(int idCat);
        Categoria* dameCategoria(int idCat);
=======
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        list<DtJuego*> buscarPorCategoria(int catId);
};

#endif