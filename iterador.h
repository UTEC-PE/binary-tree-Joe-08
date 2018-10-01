#include <iostream>
#include <stack>
#include "nodo.h"
using namespace std;

class iterador{
private:
	Nodo *corriente;
public:
	stack<Nodo*> miStack;
	iterador(){
		corriente = NULL;
    }
    iterador(Nodo* nodo){
      	this->corriente = nodo;
    }
    iterador operator++(){
      	miStack.pop();
      	corriente = miStack.top();
    }
    bool operator!=(iterador other){
    	return corriente->dato != other.corriente->dato;
    }
    int operator*(){
      	return corriente->dato;
    }
    iterador setStack(stack<Nodo*> s){
    	miStack = s;
    	return *this;
    }
    iterador begin(){
    	this->corriente = miStack.top();
    	return *this;
    }
};