#ifndef IC_INFOJUEGO
#define IC_INFOJUEGO

#include <iostream>

using namespace std;

class ICInfoJuego {
   public:
    virtual list<string> listarJuegos() = 0;
	virtual DtJuego* selectJuego(string nombre) = 0;
};
#endif