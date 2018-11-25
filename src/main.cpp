#include <iostream>
#include "agenda.h"

int main(){

	Agenda a;
	
	a.insereContato("Igor", "Igor", "84 99999-0000", "84 99999-0000", "igor@gmail.com");
	a.insereContato("Gdiael", "Gdi", "84 98805-4083", "84 98805-4083", "gdiael.barros@gmail.com");
	a.listaContato();
	std::cout << a.buscaContato("Igor");

	return 0;
}