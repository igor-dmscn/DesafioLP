/**
 * @file agenda.cpp
 * @brief Arquivo com a implementação dos metódos da Agenda.
 */

#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

/**
 * @brief Construtor sem parametros
 */
Agenda::Agenda(){}

/**
 * @brief Insere um Contato na Agenda
 *
 * @param  nome_     Nome do contato
 * @param  apelido_  Apelido do contato
 * @param  celular_  Número do celular
 * @param  wpp_      Numero do WhatsApp
 * @param  email_    Email do contato
 */
void Agenda::insereContato(string nome_, string apelido_, string celular_, string wpp_, string email_){
	Contato c(nome_, apelido_, celular_, wpp_, email_);
	
	/** Cria o contato, depois insere no multimap passando o nome e o contato */
	m_contatos.insert(std::pair<string, Contato>(nome_, c));
}

/**
 * @brief Deleta um contato da Agenda
 *
 * @param  nome_  Deleta o contato pelo nome recebido
 */
void Agenda::removeContato(string nome_){
	m_contatos.erase(nome_);
}

/**
 * @brief      Procura um contato na Agenda.
 *
 * @param  nome_  Nome do contato procurado
 *
 * @return Retorna o Contato caso a lista não esteja vazia
 */
Contato Agenda::buscaContato(string nome_){
	return m_contatos.find(nome_)->second;
}

/**
 * @brief Lista todos os contatos da agenda caso não esteja vazia
 */
void Agenda::listaContato(){
	if(this->m_contatos.size() > 0){
		for(auto it = m_contatos.begin(); it != m_contatos.end(); it++){
			cout << it->second;
		}
	}else{
		cout << "A agenda esta vazia, nao eh possivel listar contatos!" << endl;
	};
}

/**
 * @brief  Exporta os dados da agenda para um arquivo .csv
 */
void Agenda::exportToCsv(){
	string fName = "contatos.csv";
	if(this->m_contatos.size() > 0){
		ofstream arq(fName);
		if(arq.is_open() == 0){
			cout << "Nao foi possivel exportar o arquivo de contatos!" << endl;
        	return;
		};
		int count = 0;
		for(auto it = this->m_contatos.begin(); it != this->m_contatos.end(); it++){
			arq << it->second.toCsv() << endl;
			count++;
		};
		cout << "Foram exportados " << count << " contatos para o arquivo " << fName << endl;
	}else{
		cout << "A agenda esta vazia, não eh possivel exportar contatos." << endl;
	};
}


/**
 * @brief Importa os dados de um arquivo .csv para a agenda
 */
void Agenda::importFromCsv(){
	string fName = "contatos.csv";
	ifstream arq(fName);
    string linha;
    if(arq.is_open() == 0){
		cout << "Nao foi possivel importar o arquivo [" << fName << "]!" << endl;
		cout << "Verifique se ele existe e está acessível." << endl;
        return;
    };
	unsigned count = 0;
    while(getline(arq, linha)){
        Contato c(linha);
		if(c.isValid()){
			m_contatos.insert(std::pair<string, Contato>(c.getNome(), c));
			count++;
		} 
    };
	if(count > 0){
		cout << "Foram importados " << count << " contatos!" << endl;
	}else{
		cout << "Nao foram encontrados contatos no arquivo [" << fName << "]!" << endl;
	};
}