#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

Agenda::Agenda(){}

void Agenda::insereContato(string nome_, string apelido_, string celular_, string wpp_, string email_){
	Contato c(nome_, apelido_, celular_, wpp_, email_);
	m_contatos.insert(std::pair<string, Contato>(nome_, c));
}

void Agenda::removeContato(string nome_){
	m_contatos.erase(nome_);
}

Contato Agenda::buscaContato(string nome_){
	return m_contatos.find(nome_)->second;
}

void Agenda::listaContato(){
	for(auto it = m_contatos.begin(); it != m_contatos.end(); it++){
		cout << it->second;
	}
}

void Agenda::exportToCsv(){
	if(this->m_contatos.size() > 0){
		// TO_DO
	};
}

void Agenda::importFromCsv(){
	// TO_DO
}