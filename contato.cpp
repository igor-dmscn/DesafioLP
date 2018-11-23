#include <iostream>
#include <string>

#include "contato.h"

Pessoa::Pessoa(string nome_, string apelido_, string celular_, string wpp_, string email_):
	m_nome(nome_), m_apelido(apelido_), m_celular(celular_), m_wpp(wpp_), m_email(email_){}

Pessoa::~Pessoa(){}

string Pessoa::getNome(){
	return m_nome;
}

string Pessoa::getApelido(){
	return m_apelido;
}

string Pessoa::getCelular(){
	return m_celular;
}

string Pessoa::getWpp(){
	return m_wpp;
}

string Pessoa::getEmail(){
	return m_email;
}

ostream& operator<<(ostream& o, const Pessoa& p){  
    o << "Nome: " << p.m_nome << endl << "Apelido: " << p.m_apelido << endl << "Celular: " << p.m_celular 
    << endl << "WhatsApp: " << p.m_wpp << endl << "Email: " p.m_email;  
    return o;
}