#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa{
	private:
		string m_nome;
		string m_apelido;
		string m_celular;
		string m_wpp;
		string m_email;

	public:
		Pessoa(string nome_, string apelido_, string celular_, string wpp_, string email_);
		~Pessoa();

		string getNome();
		string getApelido();
		string getCelular();
		string getWpp();
		string getEmail();

	friend ostream& operator<<(ostream& o, const Pessoa& p);

};

#endif