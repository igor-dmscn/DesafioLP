#include <iostream>
#include <string>

#include "contato.h"

Contato::Contato(string nome_, string apelido_, string celular_, string wpp_, string email_):
	m_nome(nome_), m_apelido(apelido_), m_celular(celular_), m_wpp(wpp_), m_email(email_){}

Contato::~Contato(){}

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
	return this->m_nome + ";" + this->m_apelido + ";" + this->m_email + ";" + this->m_celular + ";" + this->m_wpp;  
}

ostream& operator<<(ostream& o, const Contato& p){  
    o << p.m_nome << " [" << p.m_apelido << "] " << p.m_email << " | cell: " << p.m_celular << " | zap: " << p.m_wpp << endl;  
    return o;	
}