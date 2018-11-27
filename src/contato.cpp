/**
 * @file contato.cpp
 * @brief Arquivo com a implementação dos metódos do Contato.
 */
#include <iostream>
#include <string>

#include "contato.h"

/**
 * @brief Construtor parametrizado para a classe Agenda
 *
 * @param  nome_     Nome do contato
 * @param  apelido_  Apelido do contato
 * @param  celular_  Número do celular
 * @param  wpp_      Numero do WhatsApp
 * @param  email_    Email do contato
 */
Contato::Contato(string nome_, string apelido_, string celular_, string wpp_, string email_):
	m_nome(nome_), m_apelido(apelido_), m_celular(celular_), m_wpp(wpp_), m_email(email_){}

/**
 * @brief  Contrutor parametrizado que recebe a linha do CSV
 *
 * @param  linhaCsv  A linha vinda do arquivo
 */
Contato::Contato(string linhaCsv){
	vector<string> colunas = this->splitString(linhaCsv, ';');
	/** Caso o vetor não possua a quantidade correta de elementos, o contato será inválido
		Então esvaziamos o vetor e preenchemos ele com string vazias */
	if(colunas.size() != 5){
		colunas.clear();
		for(int i = 0; i < 6; i++) colunas.push_back("");
	}
	this->m_nome = colunas[0];
	this->m_apelido = colunas[1];
	this->m_celular = colunas[2];
	this->m_wpp = colunas[3];
	this->m_email = colunas[4];
}

/**
 * @brief  Destroi o objeto.
 */
Contato::~Contato(){}

/**
 * @brief	Método auxiliar para quebra da string em um vetor de string de acordo com um delimitador
 *
 * @param	linha        string a ser quebrada
 * @param	delimitador  caractere que determina a quebra
 *
 * @return 
 */
vector<string> Contato::splitString(string& linha, char delimitador){
	vector<string> colunas;
	string buffer = "";
	for(unsigned i = 0; i < linha.size(); i++){
		char c = linha[i];
		if(c == delimitador){
			colunas.push_back(buffer);
			buffer = "";
		}else{
			string letra(1, c);
			buffer += letra;
		};
	};
	if(buffer != "") colunas.push_back(buffer);
	return colunas;
}

/**
 * @brief      Retorna o nome do Contato.
 *
 * @return     Nome do contato.
 */
string Contato::getNome(){
	return m_nome;
}

/**
 * @brief      Retorna o apelido do contato.
 *
 * @return     Apelido do contato.
 */
string Contato::getApelido(){
	return m_apelido;
}

/**
 * @brief      Retorna o número do celular.
 *
 * @return     String com o número do celular.
 */
string Contato::getCelular(){
	return m_celular;
}

/**
 * @brief      Retorna o número do WhatsApp.
 *
 * @return     String com o número do WhatsApp.
 */
string Contato::getWpp(){
	return m_wpp;
}

/**
 * @brief      Retorna o email do contato.
 *
 * @return     String com o email.
 */
string Contato::getEmail(){
	return m_email;
}

/**
 * @brief      Retorna todas as informações do contato, separados por ';' para o arquivo .csv
 *
 * @return     String unica com as informações do contato
 */
string Contato::toCsv(){
	return this->m_nome + ";" + this->m_apelido + ";" + this->m_celular + ";" + this->m_wpp + ";" + this->m_email;  
}

/**
 * @brief      Determina se alguma informação do contato está faltando
 *
 * @return     True se for válido, False caso contrário
 */
bool Contato::isValid(){
	return (this->m_nome != "") && (this->m_apelido != "") && (this->m_celular != "") && (this->m_wpp != "") && (this->m_email != "");
}

/**
 * @brief      Sobrecarga do operador de inserção
 *
 * @param  o    Variável do tipo ostream que corresponde ao stream de saída
 * @param  p    Variável do tipo Contato que corresponde ao contato a ser impresso
 *
 * @return     Stream de saída com os dados do contato formatados
 */
ostream& operator<<(ostream& o, const Contato& p){  
    o << p.m_nome << " [" << p.m_apelido << "] Cell: " << p.m_celular << " | Whats: " << p.m_wpp << " | E-mail: " << p.m_email << endl;  
    return o;	
}