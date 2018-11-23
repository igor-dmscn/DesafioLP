#include <iostream>
#include "agenda.h"

int main(){

	Agenda a;
	
	a.insereContato("Igor Bruno Damasceno", "Igor", "99999", "999999", "igor");
	a.listaContato();

	return 0;
}