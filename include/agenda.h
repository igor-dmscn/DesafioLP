
/**
 * @file agenda.h
 * @brief Arquivo .h com as definições da classe Agenda.
 */

#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <fstream>
#include <map>

#include "contato.h"

using namespace std;


class Agenda{
	private:
		/** Container multimap para salvar os contatos na agenda */
		multimap<string, Contato> m_contatos;

	public:
		Agenda();
		
		/** Insere contato na agenda. */
		void insereContato(string nome_, string apelido_, string celular_, string wpp_, string email_);

		/** Apaga o contato da agenda passando o nome. */
		void removeContato(string nome_);

		/** Busca o contato pelo nome. */
		Contato buscaContato(string nome_);
		
		/** Lista os contatos da agenda. */
		void listaContato();

		/** Exporta os dados da agenda para um arquivo .csv */
		void exportToCsv();

		/** Importa de um arquivo .csv para a agenda */
		void importFromCsv();
};

#endif
