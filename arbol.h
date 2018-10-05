#include <iostream>
#include "nodo.h"
#include "iterador.h"
using namespace std;

class Arbol{
private:
	Nodo *root;
public:
	stack<Nodo*> s;
	Arbol(){root = NULL;}
	~Arbol(){};
	void insertar(int data){ 
		if (root)
			root->insertar(root,data);
		else
			root = new Nodo{data,NULL,NULL};
	}
	void printenOrden(){
		if (root){
			root->printenOrden(root);
			cout<<endl;
		}
	}
	void printpreOrden(){
		if (root){
			root->printpreOrden(root);
			cout<<endl;
		}
	}
	void printpostOrden(){
		if (root){
			root->printpostOrden(root);
			cout<<endl;
		}
	}
	int peso(){ // Esto debería retornar el peso, no imprimirlo
		/*if (root)
			cout<<root->peso(root)<<endl;*/
		return root->peso(root); // De esta manera
	}
	void remover(int data){
		if (root)
			root->remover(root,data);
	}
	iterador begin(){
		return iterador(root->minNodo(root));
	}
	iterador end(){
		return iterador(root->maxNodo(root));
	}
    stack<Nodo*> getStack(){
    	return s;
    }
};
//iterador(en orden)
	