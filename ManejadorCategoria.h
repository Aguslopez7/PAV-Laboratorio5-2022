#ifndef MANEJADOR_CATEGORIA
#define MANEJADOR_CATEGORIA

#include <list>
#include <map>
#include "Categoria.h"
<<<<<<< HEAD

using namespace std;
=======
#include "DtCategoria.h"
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

class ManejadorCategoria
{
	private:
		static ManejadorCategoria *instancia;
		ManejadorCategoria();
		map<int, Categoria*> colCategorias; // string, string (genero , plataforma)
	public:
		static ManejadorCategoria* getInstancia();
<<<<<<< HEAD
        list<Categoria*> listarCategorias(); // Verificar
=======
        list<DtCategoria*> listarCategorias(); // Verificar
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
		Categoria* find(int id); // Verificar
		void add(Categoria* categoria);
		void erase(int id);
		virtual ~ManejadorCategoria();
};

#endif 