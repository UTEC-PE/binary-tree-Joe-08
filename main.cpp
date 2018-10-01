#include "arbol.h"

int main(int argc, char const *argv[])
{
	Arbol a;
	a.insertar(20);
	a.insertar(15);
	a.insertar(25);
	a.insertar(10);
	a.insertar(30);
	a.printenOrden();
	//a.peso();
	//a.printpreOrden();
	//a.printpostOrden();
	iterador ite;
	ite.setStack(a.getStack());
	for (ite = ite.begin();ite.miStack.size() > 1; ++ite){
		cout<<*ite<<" ";
	}
	cout<<*ite<<endl;
	return 0;
}