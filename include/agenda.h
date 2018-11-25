#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <map>

#include "contato.h"

using namespace std;

class Agenda{
	private:
		multimap<string, Contato> m_contatos;

	public:
		Agenda();
		void insereContato(string nome_, string apelido_, string celular_, string wpp_, string email_);
		void removeContato(string nome_);
		Contato buscaContato(string nome_);
		void listaContato();
		void exportToCsv();
		void importFromCsv();
};

#endif
