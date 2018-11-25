#ifndef CONTATO_H
#define CONTATO_H

#include <string>
#include <vector>

using namespace std;

class Contato{
	private:
		string m_nome;
		string m_apelido;
		string m_celular;
		string m_wpp;
		string m_email;
		vector<string> splitString(string& linha, char delimitador);

	public:
		Contato(string nome_, string apelido_, string celular_, string wpp_, string email_);
		Contato(string linhaCsv);
		~Contato();

		string getNome();
		string getApelido();
		string getCelular();
		string getWpp();
		string getEmail();
		string toCsv();
		bool isValid();

	friend ostream& operator<<(ostream& o, const Contato& p);

};

#endif