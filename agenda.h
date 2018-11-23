#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>

#include "pessoa.h"

#define MAX_CONTATOS 100

using namespace std;

class Agenda{
	private:
		Pessoa * m_contatos[MAX_CONTATOS];
		int m_total_contatos;

	public:
		Agenda();
		void insereContato(string nome_, int idade_, float altura_);
		void removeContato(string nome_);
		int buscaContato(string nome_);
		void listaContato(char letra_);
		void listaContato();
		void imprimeContato(int i);

};

#endif
