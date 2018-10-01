#ifndef NODO_H
#define NODO_H 

#include <iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo *izq,*der;
	void insertar(Nodo *&nodo, int data){
		if (!nodo){
			nodo = new Nodo;
			nodo->dato = data;
			nodo->izq = NULL;
			nodo->der = NULL;
		}else if (data < nodo->dato)
			insertar(nodo->izq,data);
		else if (data > nodo->dato)
			insertar(nodo->der,data);
	}
	void printenOrden(Nodo *nodo){
		if(nodo->izq)
			printenOrden(nodo->izq);
		cout<<nodo->dato<<" ";
		if(nodo->der)
			printenOrden(nodo->der);
	}
	void printpreOrden(Nodo *&nodo){
		cout<<nodo->dato<<" ";
		if(nodo->izq)
			printenOrden(nodo->izq);
		if(nodo->der)
			printenOrden(nodo->der);
	}
	void printpostOrden(Nodo *&nodo){
		if(nodo->izq)
        	printenOrden(nodo->izq);
    	if(nodo->der)
        	printenOrden(nodo->der);
        cout<<nodo->dato<<" ";
	}
	int peso(Nodo *nodo){
		int contador = 1;
		if (!nodo)
	        return 0; 
	    else{
	    	contador += peso(nodo->izq);
	    	contador += peso(nodo->der);
	    	return contador;	
	    }  
	}
	Nodo *minNodo(Nodo *nodo){
		if (!nodo) return NULL;
		while (nodo->izq != NULL){
			nodo = nodo->izq;
		}
	}
	Nodo *maxNodo(Nodo *nodo){
		if (!nodo) return NULL;
		while (nodo->der != NULL){
			nodo = nodo->der;
		}
	}
	Nodo *remover(Nodo *root, int data){
		if (!root) return NULL;
		else if (data < root->dato) root->izq = remover(root->izq,data);
		else if (data > root->dato)	root->der = remover(root->der,data);
		else{
			if (root->izq == NULL && root->der == NULL){
				delete root;
				root = NULL;
			}else if (root->izq == NULL){
				Nodo *temp = root;
				root = root->der;
				delete temp;
			}else if (root->der == NULL){
				Nodo *temp = root;
				root = root->izq;
				delete temp;
			}else{
				Nodo *temp = minNodo(root->der);
				root->dato = temp->dato;
				root->der = remover(root->der,temp->dato);
			} 
		}
		return root;
	}
};

#endif