#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H
#include <iostream>
#include "pessoa.h"
using namespace std;

class Passageiro : public Pessoa{             // Classe Passageiro herda publicamente da classe Pessoa
    string bilhete;                           // Armazena o número do bilhete do passageiro
    string cpf;                               // Armazena o CPF do passageiro
public:
    Passageiro(string nome, string bilhete, string cpf); // Construtor que recebe nome, bilhete e CPF
    virtual ~Passageiro() {};                // Destrutor virtual (boa prática para herança)

    string serializar();                     // Converte os dados do passageiro para string (para salvar em arquivo)
    static Passageiro* desserializar(const string& linha); // Cria um objeto Passageiro a partir de uma linha de texto
    void exibirDados();                      // Exibe os dados do passageiro no terminal

    //getters
    string getBilhete() const {return bilhete; }   
    string getCpf() const {return cpf; }           

    //setters
    void setBilhete(string bilheteNovo) { bilhete = bilheteNovo; }
    void setCpf(string cpfNovo) { cpf = cpfNovo; }                 
};

#endif 