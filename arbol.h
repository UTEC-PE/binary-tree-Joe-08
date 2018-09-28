#include <iostream>
#include "nodo.h"

using namespace std;

class Arbol{
private:
	Nodo *root;
public:
	Arbol(){root = NULL;}
	~Arbol(){};
	void insertar(int data){ 
		if (root)
			root->insertar(root,data);
		else{
			root = new Nodo{data,NULL,NULL};
		}
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
	int peso(){
		if (root)
			cout<<root->peso(root)<<endl;
	}
	void remover(int data){
		if (root){
			root->remover(root,data);
			cout<<endl;
		}
	}
};
//iterador(en orden)
	