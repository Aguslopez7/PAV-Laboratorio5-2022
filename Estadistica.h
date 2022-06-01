#ifndef ESTADISTICA
#define ESTADISTICA

#include <iostream>
#include "Estadistica.h"

using namespace std;

class Estadistica{
    private:
        int puntaje;
    public:
        Estadistica();
        Estadistica(int puntaje);
        void setPuntaje(int puntaje);
        int getPuntaje();
        ~Estadistica();
};

#endif