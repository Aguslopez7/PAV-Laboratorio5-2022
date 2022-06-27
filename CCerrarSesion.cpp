#include "CCerrarSesion.h"
#include "Sesion.h"

void CCerrarSesion::cerrarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    sesion->setUsuario(NULL);
}