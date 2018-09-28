#include <iostream>
#include "arbol.h"
using namespace std;

int main(int argc, char const *argv[]){
	Arbol a;
	a.insertar(1);
	a.insertar(2);
	a.insertar(3);
	a.insertar(-1);
	a.insertar(0);
	a.remover(2);
	a.printenOrden();
	//a.peso();
	//a.printpreOrden();
	//a.printpostOrden();
	return 0;
}