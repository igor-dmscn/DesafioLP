#include <iostream>
#include "agenda.h"

int main(){

	Agenda a;
	
	a.insereContato("Igor", "Igor", "99999", "999999", "igor");
	a.listaContato();
	std::cout << a.buscaContato("Igor");

	return 0;
}