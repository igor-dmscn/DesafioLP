#include <iostream>
#include <string>

#include "contato.h"

Contato::Contato(string nome_, string apelido_, string celular_, string wpp_, string email_):
	m_nome(nome_), m_apelido(apelido_), m_celular(celular_), m_wpp(wpp_), m_email(email_){}

Contato::Contato(string linhaCsv){
	vector<string> colunas = this->splitString(linhaCsv, ';');
	// Caso o vetor não possua a quantidade correta de elementos, o contato será inválido
	// Então esvaziamos o vetor e preenchemos ele com string vazias
	if(colunas.size() < 5){
		colunas.clear();
		for(int i = 0; i < 6; i++) colunas.push_back("");
	}
	this->m_nome = colunas[0];
	this->m_apelido = colunas[1];
	this->m_celular = colunas[2];
	this->m_wpp = colunas[3];
	this->m_email = colunas[4];
}

Contato::~Contato(){}

vector<string> Contato::splitString(string& linha, char delimitador){
	vector<string> colunas;
	string buffer = "";
	for(unsigned i = 0; i < linha.size(); i++){
		char c = linha[i];
		if(c == delimitador){
			colunas.push_back(buffer);
			buffer = "";
		}else{
			buffer += to_string(c);
		};
	};
	if(buffer != "") colunas.push_back(buffer);
	return colunas;
}

string Contato::getNome(){
	return m_nome;
}

string Contato::getApelido(){
	return m_apelido;
}

string Contato::getCelular(){
	return m_celular;
}

string Contato::getWpp(){
	return m_wpp;
}

string Contato::getEmail(){
	return m_email;
}

string Contato::toCsv(){
	return this->m_nome + ";" + this->m_apelido + ";" + this->m_celular + ";" + this->m_wpp + ";" + this->m_email;  
}

bool Contato::isValid(){
	return (this->m_nome != "") && (this->m_apelido != "") && (this->m_celular != "") && (this->m_wpp != "") && (this->m_email != "");
}

ostream& operator<<(ostream& o, const Contato& p){  
    o << p.m_nome << " [" << p.m_apelido << "] Cell: " << p.m_celular << " | Whats: " << p.m_wpp << " | E-mail: " << p.m_email << endl;  
    return o;	
}