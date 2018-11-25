#include <iostream>
#include "agenda.h"

int main(){

	Agenda a;

	std::cout << endl << "Adicionando contatos a agenda" << endl << endl;

	a.insereContato("Igor", "Igor", "84 99999-0000", "84 99999-0000", "igor@gmail.com");
	a.insereContato("Gdiael", "Gdi", "84 98805-4083", "84 98805-4083", "gdiael.barros@gmail.com");
	a.insereContato("Manoela","Manu", "84 99930-0303", "84 99930-0303", "manuela.souza@gmail.com");

	a.listaContato();

	a.exportToCsv();

	std::cout << endl << "Procurando contato: Igor" << endl;
	std::cout << a.buscaContato("Igor");

	std::cout << endl << "Criando uma nova agenda." << endl;
	Agenda b;
	b.importFromCsv();
	b.listaContato();

	return 0;
}