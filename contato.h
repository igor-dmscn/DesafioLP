#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>
#include <string>

using namespace std;

class Contato{
	private:
		string m_nome;
		string m_apelido;
		string m_celular;
		string m_wpp;
		string m_email;

	public:
		Contato(string nome_, string apelido_, string celular_, string wpp_, string email_);
		~Contato();

		string getNome();
		string getApelido();
		string getCelular();
		string getWpp();
		string getEmail();
		string toCsv();

	friend ostream& operator<<(ostream& o, const Contato& p);

};

#endif