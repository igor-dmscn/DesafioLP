#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

Agenda::Agenda():m_total_contatos(0){}

void Agenda::insereContato(string nome_, int idade_, float altura_){
	Pessoa * p = new Pessoa(nome_, idade_, altura_);
	if(m_total_contatos < MAX_CONTATOS){
		m_contatos[m_total_contatos++] = p;
	}
}

void Agenda::removeContato(string nome_){
	m_contatos[this->buscaContato(nome_)] = m_contatos[m_total_contatos-1];
	m_contatos[m_total_contatos-1] = nullptr;
	m_total_contatos--;
}

int Agenda::buscaContato(string nome_){
	for(int i = 0; i<m_total_contatos; i++){
		if(m_contatos[i]->getNome() == nome_){
			return i;
		}
	}
	return -1;
}

void Agenda::listaContato(char letra_){
	string aux;
	for(int i=0; i<m_total_contatos; i++){
		aux = m_contatos[i]->getNome();
		if(aux[0] == letra_){
			cout << *m_contatos[i] << endl;
		}
	}
}

void Agenda::listaContato(){
	for(int i=0; i<m_total_contatos; i++){
		cout << *m_contatos[i] << endl;
	}
}

void Agenda::imprimeContato(int i){
	cout << *m_contatos[i] << endl;
}
