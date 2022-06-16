#ifndef IC_INFOJUEGO
#define IC_INFOJUEGO

#include <iostream>
<<<<<<< HEAD

=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
using namespace std;

class ICInfoJuego {
   public:
    virtual list<string> listarJuegos() = 0;
	virtual DtJuego* selectJuego(string nombre) = 0;
};
#endif