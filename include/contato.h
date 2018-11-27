/**
 * @file contato.h
 * @brief Arquivo .h com as definições da classe Contato.
 */

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

		/** Vector do tipo String para separar as informações do contato para o arquivo csv */
		vector<string> splitString(string& linha, char delimitador);

	public:
		/** Construtores e destrutor padrão */
		Contato(string nome_, string apelido_, string celular_, string wpp_, string email_);
		Contato(string linhaCsv);
		~Contato();

		
		/** Métodos get */
		string getNome();
		string getApelido();
		string getCelular();
		string getWpp();
		string getEmail();
		string toCsv();

		/** Método para verificar se o contato tem algum campo em branco. */
		bool isValid();

		/** Sobrecarga do operador de inserção */
		friend ostream& operator<<(ostream& o, const Contato& p);

};

#endif