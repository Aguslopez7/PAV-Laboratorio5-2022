#ifndef MANEJADOR_CATEGORIA
#define MANEJADOR_CATEGORIA

#include <list>
#include <map>
#include "Categoria.h"

using namespace std;

class ManejadorCategoria
{
	private:
		static ManejadorCategoria *instancia;
		ManejadorCategoria();
		map<int, Categoria*> colCategorias; 
	public:
		static ManejadorCategoria* getInstancia();
        list<Categoria*> listarCategorias(); 
		Categoria* find(int id); 
		void add(Categoria* categoria);
		bool existeCat(int id);
		void erase(int id);
		virtual ~ManejadorCategoria();
};

#endif 