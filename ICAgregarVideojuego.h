#ifndef ICAGREGARVIDEOJUEGO
#define ICAGREGARVIDEOJUEGO

#include <iostream> 
#include "DtJuego.h"
<<<<<<< HEAD

=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
using namespace std;

class ICAgregarVideojuego{
    public:
<<<<<<< HEAD
    virtual void solicitarInfo(string nombre,string descripcion,int costo)=0;
    //virtual list<DtJuego*> listarDtJuegos()=0;
    virtual void confirmarJuego()=0;
    virtual void agregarCategoria(DtCategoria* dt)=0;
=======
    virtual void solicitarInfo(string nombre,string descripcion,int costo, DtCategoria* dtCategoria)=0;
    virtual list<DtJuego*> listarJuegos()=0;
    virtual void confirmarJuego()=0;
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
    virtual void cancelar()=0;
};
#endif